#include <iostream>

using namespace std;

template<typename T>

struct Node {
    Node* next;
    T obj;
    Node(T o, Node* n=nullptr)
    : obj(o), next(n) { }
};

template<typename T>
int count_nodes(const Node<T>* node) {
    if(node == nullptr) {
        return 0;
    } else {
        return 1 + count_nodes(node->next);
    }
}