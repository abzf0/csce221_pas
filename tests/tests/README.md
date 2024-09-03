# Comparator Exercise
This exercise is meant to expand your understanding of comparators by demonstrating how they might be implemented. You have worked with comparators in PA2 and will continue to work with them in future PAs, so it is important that you understand how to work with them.

## Assignment
There is also documentation comments in the code that describes each of these functions.

### Student.h
There are two functions to complete in `Student.h`. You can complete them in the order listed.

----
`GPAComparator::operator()`

**Description:** Describes an ordering ascending on GPA primarily and descending on ID secondly.

**Complexity: O(1)**

----
`KnownOrderComparator::operator()`

**Description:** Describes an ordering that matches the ordering of `_student_ranking`.

**Complexity: O(n)**

## Submission
Submit `src/Student.h` to Gradescope.
