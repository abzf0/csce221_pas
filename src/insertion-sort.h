/**
 * @file insertion-sort.h
 * @author your name (netid@tamu.edu)
 * @brief Declares and defines the Insertion Sort
 * @version 0.1
 * @date 2022-01-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include "sort.h"

template <class T, class Comparator = std::less<T> >
class InsertionSort : public Sort<T, Comparator> {
public:
    void operator()(std::vector<T> vector) override {
        
    }

    [[nodiscard]] virtual const char* getName() const noexcept { return "Insertion Sort"; }
};

#endif
