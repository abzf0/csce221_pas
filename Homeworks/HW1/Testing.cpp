#include <iostream>
#include <vector>
#include <stdexcept>
#include <cmath>
#include "Problems_2_Binary_Search.h"

using namespace std;

int main() {
    vector<int> v;
    int k = 11;
    int max_val = (int)pow(2, k);

    for (int n = max_val; n >= 1; n--) {
        v.push_back(n);
        cout << n << ". " << "-> ";
        binarySearch(v, n, greater<int>());
    }

    return 0;
}
