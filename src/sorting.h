#pragma once

#include <functional> // std::less

// This is C++ magic which will allows our function
// to default to using a < b if a comparator is not
// specified. Essentially, it defines std::less<T>
// for the iterator's value_type.
//
// If you have a vector<float>, the iterator's value
// type will be float

namespace {
	template<typename RandomIter>
	using less_for_iter = std::less<typename RandomIter::value_type>; 
}

template<typename RandomIter, typename Comparator = less_for_iter<RandomIter>>
void bubble_sort(RandomIter begin, RandomIter end, Comparator comp = Comparator{}) {
	// You can add more of these aliases if necessary
	using difference_type = typename RandomIter::difference_type;

	// COMPLETE
}

template<typename RandomIter, typename Comparator = less_for_iter<RandomIter>>
void insertion_sort(RandomIter begin, RandomIter end, Comparator comp = Comparator{}) {
	using difference_type = typename RandomIter::difference_type;

    // COMPLETE
}

template<typename RandomIter, typename Comparator = less_for_iter<RandomIter>>
void selection_sort(RandomIter begin, RandomIter end, Comparator comp = Comparator{}) {
	using difference_type = typename RandomIter::difference_type;

    // COMPLETE
}
