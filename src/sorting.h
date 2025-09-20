#pragma once

#include <functional> // std::less
#include <iterator> // std::iterator_traits

namespace sort {

	// This is C++ magic which will allows our function
	// to default to using a < b if the comparator arg
	// is unspecified. It uses defines std::less<T>
	// for the iterator's value_type.
	//
	// For example: if you have a vector<float>, the 
	// iterator's value type will be float. std::less 
	// will select the < for sorting floats as the 
	// default comparator.
	template<typename RandomIter>
	using less_for_iter = std::less<typename std::iterator_traits<RandomIter>::value_type>;

	/* Efficiently swap two items - use this to implement your sorts */
	template<typename T>
	void swap(T & a, T & b) noexcept { 
		T temp = std::move(a); 
		a = std::move(b); 
		b = std::move(temp); 
	}

	template<typename RandomIter, typename Comparator = less_for_iter<RandomIter>>
	void bubble(RandomIter begin, RandomIter end, Comparator comp = Comparator{}) {
		// Random access iterators have the same traits you defined in the Vector class
		// For instance, difference_type represents an iterator difference
		// You may delete the types you don't use to remove the compiler warnings
		using _it             = std::iterator_traits<RandomIter>;
		using difference_type = typename _it::difference_type;
		using value_type      = typename _it::value_type;
		using reference       = typename _it::reference;
		using pointer         = typename _it::pointer;


		difference_type dif = end - begin;
		if(dif<=1) return;

		for(difference_type i = 0; i < dif - 1; i++) {
			bool sorted = true;
			for(difference_type j = 0; j < dif - 1 - i; j++) {
				reference el1 = *(begin + j);
				reference el2 = *(begin + j + 1);
				
				if(comp(el2, el1)) {
					swap(el2, el1);
					sorted = false;
				}
			} if(sorted) break;
		}
		

		
	}

	template<typename RandomIter, typename Comparator = less_for_iter<RandomIter>>
	void insertion(RandomIter begin, RandomIter end, Comparator comp = Comparator{}) { 
		using _it             = std::iterator_traits<RandomIter>;
		using difference_type = typename _it::difference_type;
		using value_type      = typename _it::value_type;
		using reference       = typename _it::reference;
		using pointer         = typename _it::pointer;

		difference_type dif = end - begin;
		if(dif<=1) return;

		for(RandomIter i = begin + 1; i < end; i++) {
			value_type n = std::move(*i);

			RandomIter j = i;
			while(j > begin && comp(n,*(j-1))) {
				 swap(*(j - 1), *j); j--;
			}
		}
	 }

	template<typename RandomIter, typename Comparator = less_for_iter<RandomIter>>
	void selection(RandomIter begin, RandomIter end, Comparator comp = Comparator{}) { 
		using _it             = std::iterator_traits<RandomIter>;
		using difference_type = typename _it::difference_type;
		using value_type      = typename _it::value_type;
		using reference       = typename _it::reference;
		using pointer         = typename _it::pointer;

		difference_type dif = end - begin;
		if(dif<=1) return;

		for(difference_type i = 0; i < dif - 1; i++)
			RandomIter minIndex = begin + i;
			for(difference_type j = i + 1; j < dif; j++) {
				if(comp(*(begin+j),*minIndex)) {
					minIndex=begin+j;
				}
			} if(minIndex!=begin+j) {
				swap(*(begin+i),*minIndex);
			}

	 }
}