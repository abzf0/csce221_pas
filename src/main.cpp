#pragma once

#include <functional> // std::less
#include <algorithm>

// This is C++ magic which will allows our function
// to default to using a < b if a comparator is not
// specified. Essentially, it defines std::less<T>
// for the iterator's value_type.
//
// If you have a vector<float>, the iterator's value
// type will be float

namespace sort {
	template<typename RandomIter>
	using less_for_iter = std::less<typename RandomIter::value_type>;


	template<typename T>
	void swap(T & a, T & b) noexcept {
		T t = std::move(a);
		a   = std::move(b);
		b   = std::move(t);
	}

	template<typename RandomIter, typename Comparator = less_for_iter<RandomIter>>
	void bubble(RandomIter begin, RandomIter end, Comparator comp = Comparator{}) {
		using _it             = std::iterator_traits<RandomIter>;
		using difference_type = typename _it::difference_type;
		
		for (difference_type num_sorted = 1; num_sorted < end - begin; ++num_sorted) {
			for (RandomIter it = begin; it + num_sorted < end; ++it) {
				if (!comp(*it, it[1])) {
					swap(*it, it[1]);
				}
			}
		}
	}

	template<typename RandomIter, typename Comparator = less_for_iter<RandomIter>>
	void insertion(RandomIter begin, RandomIter end, Comparator comp = Comparator{}) {
		using _it             = std::iterator_traits<RandomIter>;
		using difference_type = typename _it::difference_type;

		auto l = end - begin;
		for(difference_type i = 1, j; i < l; i++)
			for(j = i; j > 0 && comp(begin[j], begin[j-1]); --j)
				swap(begin[j], begin[j-1]);
	}

	template<typename RandomIter, typename Comparator = less_for_iter<RandomIter>>
	void selection(RandomIter begin, RandomIter end, Comparator comp = Comparator{}) {
		for (RandomIter it = begin; it + 1 < end; ++it) {
			RandomIter min = it;
			for (RandomIter iit = it + 1; iit < end; ++iit) {
				if (comp(*iit, *min)) {
					min = iit;
				}
			}
			swap(*it, *min);
		}
	}
}