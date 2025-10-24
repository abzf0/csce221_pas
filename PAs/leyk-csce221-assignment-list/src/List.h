#pragma once

#include <cstddef> // size_t
#include <iterator> // std::bidirectional_iterator_tag
#include <type_traits> // std::is_same, std::enable_if

template <class T>
class List {
    private:
    struct Node {
        Node *next, *prev;
        T data;
        explicit Node(Node* prev = nullptr, Node* next = nullptr)
        : next{next}, prev{prev} {}
        explicit Node(const T& data, Node* prev = nullptr, Node* next = nullptr)
        : next{next}, prev{prev}, data{data} {}
        explicit Node(T&& data, Node* prev = nullptr, Node* next = nullptr)
        : next{next}, prev{prev}, data{std::move(data)} {}
    };

    template <typename pointer_type, typename reference_type>
    class basic_iterator {
    public:
        using iterator_category = std::bidirectional_iterator_tag;
        using value_type        = T;
        using difference_type   = ptrdiff_t;
        using pointer           = pointer_type;
        using reference         = reference_type;
    private:
        friend class List<value_type>;
        using Node = typename List<value_type>::Node;

        Node* node;

        explicit basic_iterator(Node* ptr) noexcept : node{ptr} {}
        explicit basic_iterator(const Node* ptr) noexcept : node{const_cast<Node*>(ptr)} {}

    public:
        basic_iterator() { node = nullptr; };
        basic_iterator(const basic_iterator&) = default;
        basic_iterator(basic_iterator&&) = default;
        ~basic_iterator() = default;
        basic_iterator& operator=(const basic_iterator&) = default;
        basic_iterator& operator=(basic_iterator&&) = default;

        reference operator*() const {
            return node->data;
        }
        pointer operator->() const {
            return &(node->data);
        }

        // Prefix Increment: ++a
        basic_iterator& operator++() {
            node = node->next;
            return *this;
        }
        // Postfix Increment: a++
        basic_iterator operator++(int) {
            basic_iterator temp(*this);
            node = node->next;
            return temp;
            
        }
        // Prefix Decrement: --a
        basic_iterator& operator--() {
            node = node->prev;
            return *this;
        }
        // Postfix Decrement: a--
        basic_iterator operator--(int) {
            basic_iterator temp(*this);
            node = node->prev;
            return temp;
        }

        bool operator==(const basic_iterator& other) const noexcept {
            return node == other.node;
        }
        bool operator!=(const basic_iterator& other) const noexcept {
            return node != other.node;
        }
    };

public:
    using value_type      = T;
    using size_type       = size_t;
    using difference_type = ptrdiff_t;
    using reference       = value_type&;
    using const_reference = const value_type&;
    using pointer         = value_type*;
    using const_pointer   = const value_type*;
    using iterator        = basic_iterator<pointer, reference>;
    using const_iterator  = basic_iterator<const_pointer, const_reference>;

private:
    Node head, tail;
    size_type _size;

public:
    List() {
        _size = 0;
        head.next = &tail;
        head.prev = nullptr;
        tail.prev = &head;
        tail.next = nullptr;
    }
    List( size_type count, const T& value ) : List() {
        for(size_type i = 0; i < count; i++) {
            push_back(value);
        }
    }
    explicit List( size_type count ) : List() {
        for(size_type i = 0; i < count; i++) {
            push_back(T());
        }
    }
    List( const List& other ) : List() {
        for(const T& item : other) {
            push_back(item);
        }
    }
    List( List&& other ) noexcept : _size(other._size) {
        if (other._size == 0) {
            head.next = &tail;
            head.prev = nullptr;
            tail.prev = &head;
            tail.next = nullptr;
            _size = 0;
        } else {
            head.next = other.head.next;
            tail.prev = other.tail.prev;

            head.next->prev = &head;
            tail.prev->next = &tail;

            other._size = 0;
            other.head.next = &other.tail;
            other.tail.prev = &other.head;
        }
    }
    ~List() {
        Node* curr = head.next;
        while(curr != &tail) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
        head.next = &tail;
        tail.prev = &head;
        _size = 0;
    }
    List& operator=( const List& other ) {
        if(this != &other) {
            clear();
            for(const T& item : other) {
                push_back(item);
            }
        }
        return *this;
    }
    List& operator=( List&& other ) noexcept {
        if(this != &other) {
            clear();
            if (other._size == 0) {
                head.next = &tail;
                tail.prev = &head;
                _size = 0;
            } else {
                head.next = other.head.next;
                tail.prev = other.tail.prev;

                head.next->prev = &head;
                tail.prev->next = &tail;

                _size = other._size;

                other._size = 0;
                other.head.next = &other.tail;
                other.tail.prev = &other.head;
            }
        } return *this;
    }

    reference front() {
        return head.next->data;
    }
    const_reference front() const {
        return head.next->data;
    }
	
    reference back() {
        return tail.prev->data;
    }
    const_reference back() const {
        return tail.prev->data;
    }
	
    iterator begin() noexcept {
        return iterator(head.next);
    }
    const_iterator begin() const noexcept {
        return const_iterator(head.next);
    }
    const_iterator cbegin() const noexcept {
        return const_iterator(head.next);
    }

    iterator end() noexcept {
        return iterator(&tail);
    }
    const_iterator end() const noexcept {
        return const_iterator(&tail);
    }
    const_iterator cend() const noexcept {
        return const_iterator(&tail);
    }

    bool empty() const noexcept {
        return _size == 0;
    }

    size_type size() const noexcept {
        return _size;
    }

    void clear() noexcept {
        Node* curr = head.next;
        while(curr != &tail) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }

        head.next = &tail;
        tail.prev = &head;
        _size = 0;
    }

    iterator insert( const_iterator pos, const T& value ) {
        Node* newNode = new Node(value);
        Node* curr = pos.node;
        Node* prev = curr->prev;

        newNode->next = curr;
        newNode->prev = prev;
        prev->next = newNode;
        curr->prev = newNode;

        _size++;
        return iterator(newNode);
    }
    iterator insert( const_iterator pos, T&& value ) {
        Node* newNode = new Node(std::move(value));
        Node* curr = pos.node;
        Node* prev = curr->prev;

        newNode->next = curr;
        newNode->prev = prev;
        prev->next = newNode;
        curr->prev = newNode;

        _size++;
        return iterator(newNode);
    }

    iterator erase( const_iterator pos ) {
        Node* curr = pos.node;
        Node* prev = curr->prev;
        Node* next = curr->next;

        prev->next = next;
        next->prev = prev;

        delete curr;
        _size--;
        return iterator(next);
    }

    void push_back( const T& value ) {
        Node* newNode = new Node(value, tail.prev, &tail);
        tail.prev->next = newNode;
        tail.prev = newNode;
        _size++;
    }
    void push_back( T&& value ) {
        Node* newNode = new Node(std::move(value), tail.prev, &tail);
        tail.prev->next = newNode;
        tail.prev = newNode;
        _size++;
    }

    void pop_back() {
        if(_size == 0) return;
        Node* del = tail.prev;
        Node* prev = del->prev;
        prev->next = &tail;
        tail.prev = prev;
        delete del;
        _size--;
    }
	
    void push_front( const T& value ) {
        
        Node* newNode = new Node(value);
        Node* next = head.next;
        newNode->next = next;
        newNode->prev = &head;
        next->prev = newNode;
        head.next = newNode;
        _size++;
    }
	void push_front( T&& value ) {
        Node* newNode = new Node(std::move(value));
        Node* next = head.next;
        newNode->next = next;
        newNode->prev = &head;
        next->prev = newNode;
        head.next = newNode;
        _size++;
    }

    void pop_front() {
        if(_size == 0) {
            return;
        }

        Node* del = head.next;
        Node* next = del->next;
        head.next = next;
        next->prev = &head;
        delete del;
        _size--;
    }

    /*
      You do not need to modify these methods!
      
      These method provide the non-const complement 
      for the const_iterator methods provided above.
    */
    iterator insert( iterator pos, const T & value) { 
        return insert((const_iterator &) (pos), value);
    }

    iterator insert( iterator pos, T && value ) {
        return insert((const_iterator &) (pos), std::move(value));
    }

    iterator erase( iterator pos ) {
        return erase((const_iterator&)(pos));
    }
};


/*
    You do not need to modify these methods!

    These method provide a overload to compare const and 
    non-const iterators safely.
*/
 
namespace {
    template<typename Iter, typename ConstIter, typename T>
    using enable_for_list_iters = typename std::enable_if<
        std::is_same<
            typename List<typename std::iterator_traits<Iter>::value_type>::iterator, 
            Iter
        >{} && std::is_same<
            typename List<typename std::iterator_traits<Iter>::value_type>::const_iterator,
            ConstIter
        >{}, T>::type;
}

template<typename Iterator, typename ConstIter>
enable_for_list_iters<Iterator, ConstIter, bool> operator==(const Iterator & lhs, const ConstIter & rhs) {
    return (const ConstIter &)(lhs) == rhs;
}

template<typename Iterator, typename ConstIter>
enable_for_list_iters<Iterator, ConstIter, bool> operator==(const ConstIter & lhs, const Iterator & rhs) {
    return (const ConstIter &)(rhs) == lhs;
}

template<typename Iterator, typename ConstIter>
enable_for_list_iters<Iterator, ConstIter, bool> operator!=(const Iterator & lhs, const ConstIter & rhs) {
    return (const ConstIter &)(lhs) != rhs;
}

template<typename Iterator, typename ConstIter>
enable_for_list_iters<Iterator, ConstIter, bool> operator!=(const ConstIter & lhs, const Iterator & rhs) {
    return (const ConstIter &)(rhs) != lhs;
}