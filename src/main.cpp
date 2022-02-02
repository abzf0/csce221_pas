#include <cctype>
#include <chrono>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "sorting.h"

using std::chrono::duration, std::chrono::duration_cast, std::chrono::high_resolution_clock, std::chrono::time_point;
using microseconds = std::chrono::duration<double, std::micro>;
using milliseconds = std::chrono::duration<double, std::milli>;
using std::ifstream;
using std::cerr, std::cin, std::cout, std::endl, std::ostream;
using std::string;
using std::vector;

enum class Sort { BUBBLE, INSERTION, SELECTION };

template <typename T>
struct CustomComparator {
    static size_t comparisons;

    bool operator()(const T& a, const T& b) const {
        comparisons++;
        return a < b;
    }
};

template <typename T>
size_t CustomComparator<T>::comparisons = 0;

template <class T>
ostream& operator<<(ostream& o, vector<T> vec);

ostream& operator<<(ostream& o, const Sort& sort);

[[nodiscard]] vector<int> getData();

[[nodiscard]] vector<int> getFileData();

[[nodiscard]] vector<int> getManualData();

[[nodiscard]] Sort getSortingAlgorithm();

template<typename RandomIter, typename Comparator = std::less<typename std::iterator_traits<RandomIter>::value_type>>
bool testIfSorted(RandomIter begin, RandomIter end, Comparator comp = Comparator{});

int main(int argc, char** argv)
{
    vector<int> data = getData();

    cout << "Original Data: " << data << endl;

    Sort sorting_algorithm = getSortingAlgorithm();

    time_point<high_resolution_clock> start, end;

    CustomComparator<int> comp;

    switch (sorting_algorithm) {
        case Sort::BUBBLE:
        start = high_resolution_clock::now();
        sort::bubble(data.begin(), data.end(), comp);
        end = high_resolution_clock::now();
        break;
        case Sort::INSERTION:
        start = high_resolution_clock::now();
        sort::insertion(data.begin(), data.end(), comp);
        end = high_resolution_clock::now();
        break;
        case Sort::SELECTION:
        start = high_resolution_clock::now();
        sort::selection(data.begin(), data.end(), comp);
        end = high_resolution_clock::now();
        break;
    }

    duration<double> time_span = end - start;

    cout << "Sorted Data: " << data << endl;

    cout << "Running time for " << sorting_algorithm << " on a vector of " << data.size() << " ints: ";
    if (data.size() < 300) {
        cout << duration_cast<microseconds>(time_span).count() << " \u03BCs (microseconds)" << endl;
    } else {
        cout << duration_cast<milliseconds>(time_span).count() << " ms (milliseconds)" << endl;
    }

    cout << "Number of comparisons: " << CustomComparator<int>::comparisons << endl;

    if (!testIfSorted(data.begin(), data.end(), comp)) {
        cerr << "Warning: The sorted sequence IS NOT sorted!\n";
    }

    return 0;
}

template <class T>
ostream& operator<<(ostream& o, vector<T> vec) {
    o << '[';
    for (const auto& e : vec) {
        o << e;
        if (&e != &vec.back()) {
            o << ", ";
        }
    }
    return o << ']';
}

ostream& operator<<(ostream& o, const Sort& sort) {
    switch (sort) {
        case Sort::BUBBLE:
            return o << "Bubble Sort";
        case Sort::INSERTION:
            return o << "Insertion Sort";
        case Sort::SELECTION:
            return o << "Selection Sort";
        default:
            return o << "No Known Sort";
    }
}

template<typename RandomIter, typename Comparator>
bool testIfSorted(RandomIter begin, RandomIter end, Comparator comp) {
    for (RandomIter cursor = begin; cursor + 1 < end; ++cursor) {
        if (comp(cursor[1], *cursor)) {
            std::cout << (cursor - begin) << " " << *cursor << " " << cursor[1] << std::endl;
            return false;
        }
    }
    return true;
}

[[nodiscard]] vector<int> getData() {
    char input = '\0';
    do {
        if (input) {
            cout << "The character you typed did not match the below options.\n";
        }
        cout << "How do you want to enter data:"
        << "\n\t'F': Read from a File"
        << "\n\t'M': Manually"
        << "\n============================"
        << "\nOption: ";
        if (!(cin >> input)) {
            cout << "Invalid Input! Please input a single character from the list.\n";
        }
        input = std::toupper(input);
    } while (input != 'F' && input != 'M');
    switch (input) {
        case 'F':
            return getFileData();
        case 'M':
            return getManualData();
        default:
            return vector<int>{};
    }
}

[[nodiscard]] vector<int> getFileData() {
    string filepath;
    cout << "Enter Filepath to Read: ";
    cin >> filepath;
    ifstream file{filepath};
    vector<int> retval;
    if (!file.is_open()) {
        cerr << "File not found: '" << filepath << "'\n";
        return retval;
    }
    int value;
    while (file >> value) {
        retval.push_back(value);
    }
    return retval;
}

#define forever for(;;)

[[nodiscard]] vector<int> getManualData() {
    vector<int> retval;
    int value;
    cout << "Enter Values ['q' to stop]: ";
    forever {
        if (!(cin >> value)) {
            break;
        }
        retval.push_back(value);
    }
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return retval;
}

#undef forever

[[nodiscard]] Sort getSortingAlgorithm() {
    char input = '\0';
    do {
        if (input) {
            cout << "The character you typed did not match the below options.\n";
        }
        cout << "Pick Your Sorting Algorithm:"
        << "\n\t'B': Bubble Sort"
        << "\n\t'I': Insertion Sort"
        << "\n\t'S': Selection Sort"
        << "\n============================"
        << "\nOption: ";
        if (!(cin >> input)) {
            cout << "Invalid Input! Please input a single character from the list.\n";
        }
        input = std::toupper(input);
    } while (input != 'S' && input != 'I' && input != 'B');
    switch (input) {
        case 'B':
            return Sort::BUBBLE;
        case 'I':
            return Sort::INSERTION;
        case 'S':
            return Sort::SELECTION;
        default:
            throw std::runtime_error("Sort type does not exist.");
    }
}
