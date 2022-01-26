/**
 * @file sort.h
 * @author your name (netid@tamu.edu)
 * @brief Declares and defines the Sort abstract class
 * @version 0.1
 * @date 2022-01-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef SORT_H
#define SORT_H

#include <functional>
#include <vector>

template <class T, class Comparator = std::less<T> >
class Sort {
protected:
    int num_comps{0};
    Comparator comp{};
public:
    virtual void operator()(std::vector<T> vector) = 0;

    [[nodiscard]] bool testIfSorted(std::vector<T> vector) const noexcept {
        
    }

    [[nodiscard]] int getNumComparisons() const { return num_comps; }

    [[nodiscard]] virtual const char* getName() const noexcept = 0;
};

#endif
