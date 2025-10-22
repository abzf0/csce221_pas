#include <vector>
#include <iostream>

using namespace std;

template<typename T>
struct Node {
  Node<T>* left;
  Node<T>* right;
  T obj;
  Node(T o, Node<T>* l = nullptr, Node<T>* r = nullptr)
    : obj(o), left(l), right(r) { }
};

template<typename T>
int count_filled_nodes(const Node<T>* node) {
	if(node==nullptr) {
        return 0;
    }

    int count = 0;
    if(node->left!=nullptr && node->right!=nullptr) {
        count = 1;
    }

    return count + count_filled_nodes(node->left) + count_filled_nodes(node->right);
}