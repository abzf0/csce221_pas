/**
 * @file bubble-sort.h
 * @author your name (netid@tamu.edu)
 * @brief Declares and defines the Bubble Sort
 * @version 0.1
 * @date 2022-01-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include "sort.h"

template <class T, class Comparator = std::less<T> >
class BubbleSort : public Sort<T, Comparator> {
public:
    void operator()(std::vector<T> vector) override {
        
    }

    [[nodiscard]] virtual const char* getName() const noexcept { return "Bubble Sort"; }
};

#endif
