#include <iostream>
#include <list>

using namespace std;

list<int> intersect(const list<int>& l1, const list<int>& l2) {
    auto it1 = l1.begin();
    auto it2 = l2.begin();

    list<int> ans;

    while(it1 != l1.end() && it2 != l2.end()) {
        if(*it1 == *it2) {
            ans.push_back(*it1);
        } else if(*it1 < *it2) {
            it1++;
        } else {
            it2++;
        }
    } return ans;
}