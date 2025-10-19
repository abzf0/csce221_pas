#include <iostream>
#include <list>
#include "P1_1_Efficient_l1.h"
#include "P2_a_count_nodes.h"
#include "P3_a_max_value.h"
#include <string>
#include <vector>

using namespace std;

int main() {
    //q1

    list<int> l1 = {};
    list<int> l2 = {2,3,4};
    list<int> ans1 = intersect(l1,l2);

    list<int> l3 = {1,2,3,4,5};
    list<int> l4 = {2,4,6};
    list<int> ans2 = intersect(l3,l4);

    /*

    cout<<"{";
    for(int item:ans1) {cout<<item<<",";}
    cout<<"}"<<endl;

    cout<<"{";
    for(int item:ans2) {cout<<item<<",";}
    cout<<"}"<<endl;

    */

    //q2

    Node<int>* ll1_tail = new Node(0);
    Node<int>* ll1_head = new Node(1, ll1_tail);

    Node<char>* ll2_n5 = new Node('s');
    Node<char>* ll2_n4 = new Node('s',ll2_n5);
    Node<char>* ll2_n3 = new Node('s',ll2_n4);
    Node<char>* ll2_n2 = new Node('s',ll2_n3);
    Node<char>* ll2_n1 = new Node('s',ll2_n2);

    cout << "LL 1 nodes (should be 2): " << count_nodes(ll1_head) << " | LL 2 nodes (should be 5): " << count_nodes(ll2_n1) << endl;

    //q3
    vector<int> vec1 = {1,2,3,4,5}; //shud return 5
    vector<int> vec2 = {3,2,40,50,1,500,4500,2,1,3,15}; //shud return 4500
    cout << find_max_value(vec1) << endl;
    cout << find_max_value(vec2) << endl;

    return 0;
}



