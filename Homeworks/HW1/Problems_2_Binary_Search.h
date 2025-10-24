#ifndef PROBLEMS_2_BINARY_SEARCH_H
#define PROBLEMS_2_BINARY_SEARCH_H

#include <iostream>
#include <stdexcept>
#include <vector>
#include <functional>
using namespace std;

template <typename T, typename Compare>
int binarySearch(vector<T> &v, T x, Compare comp) {
    unsigned int num_comp = 0;

    for (size_t i = 1; i < v.size(); i++) {
        if (comp(v[i], v[i - 1])) {
            throw invalid_argument("vector not sorted according to comparator");
        }
    }

    int low = 0;
    int high = (int)v.size() - 1;
    int mid;

    while (low < high) {
        mid = (low + high) / 2;
        if (num_comp++, comp(v[mid], x))
            low = mid + 1;
        else
            high = mid;
    }

    if (num_comp++, !comp(x, v[low]) && !comp(v[low], x)) {
        cout << num_comp << endl;
        return low;
    }

    return -1;
}

#endif
