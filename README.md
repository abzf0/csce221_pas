# Sorting Vectors
The goal of this assignment is to implement various sorting algorithms for the [`vector`](https://en.cppreference.com/w/cpp/container/vector) data structure.
## Assignment
### Implement Sorting Algorithms
You are to implement `bubble_sort()`, `insertion_sort()`, and `selection_sort()` using iterators. 

**HINT:** Implement `swap()` first. This is going to be used in all the sorting algorithms. Move operations are your friend.

Your must implement the following functions:
| Function Name     | Function Description                                                                                                                                                         | Time Complexity            | &#35; Points            |
| -------------     | ------------------------------------------------------------------------------                                                                                               | ------------------------   | ----------------------- |
| `swap`            | swaps the position of two elements                                                                                                                                           | O(1)                       | Frequently Utilized     |
| `bubble_sort`     | Sorts elements in the range \[start, end) using the bubble sort algorithm. This sort should be optimized so the runtime function is about 1/2 n<sup>2</sup> in the worst case| O(n<sup>2</sup>)           | 33                      |
| `insertion_sort`  | Sorts elements in the range \[start, end) using the insertion sort algorithm.                                                                                                | O(n<sup>2</sup>)           | 33                      |
| `selection_sort`  | Sorts elements in the range \[start, end) using the selection sort algorithm.                                                                                                | O(n<sup>2</sup>)           | 33                      |


It may be helpful for you to consult:
- Reference for Iterators: https://en.cppreference.com/w/cpp/iterator/iterator
- Reference for Sorts: https://en.cppreference.com/w/cpp/algorithm/sort

## Turn In
Submit the modified `sorting.h` to Gradescope. In general, submit everything except `main.cpp`.
