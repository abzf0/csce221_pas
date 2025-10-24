#include <iostream>
#include <list>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val):data(val),next(nullptr) {}
};

struct DNode {
    int data;
    DNode* next;
    DNode* prev;
    DNode(int val):data(val),next(nullptr),prev(nullptr) {}
};

class SinglyLinked {
private:
    Node* head;

    void clear() {
        Node* curr = head;

        while(curr!=nullptr) {
            Node* del = curr;
            curr = curr->next;
            delete del;
        }
        head = nullptr;
    }
public: 
    SinglyLinked(): head(nullptr) {}
    ~SinglyLinked();
    SinglyLinked(const SinglyLinked& other);
    SinglyLinked(const SinglyLinked&& other);
    SinglyLinked& operator=(const SinglyLinked& other);
    SinglyLinked& operator=(const SinglyLinked&& other);

    SinglyLinked::~SinglyLinked() {
        clear();
    }

    SinglyLinked::SinglyLinked(const SinglyLinked& other) {
        
    }

    SinglyLinked::SinglyLinked(const SinglyLinked&& other) {
        head->next = other.head->next;
        other.head->next = nullptr;
    }

    SinglyLinked& operator=(const SinglyLinked& other) {
        
    }

    SinglyLinked& operator=(const SinglyLinked&& other) {

    }
};

class DoublyLinked {
private:
    DNode* head;
    DNode* tail;

    void clear() {
        DNode* curr = head;
        while(curr!=nullptr) {
            DNode* del = curr;
            curr = curr->next;
            delete del;
        }

        head = tail = nullptr;
    }

private:
    DoublyLinked(): head(nullptr), tail(nullptr) {}
    ~DoublyLinked() {
        clear();
    }
};