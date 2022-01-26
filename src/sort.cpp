/**
 * @file sort.cpp
 * @author your name (netid@tamu.edu)
 * @brief 
 * @version 0.1
 * @date 2022-01-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <chrono>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "selection-sort.h"
#include "insertion-sort.h"
#include "bubble-sort.h"

using std::chrono::duration, std::chrono::duration_cast, std::chrono::high_resolution_clock, std::chrono::milliseconds;
using std::ifstream;
using std::cerr, std::cin, std::cout, std::endl, std::ostream;
using std::string;
using std::vector;

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
    forever {
        cout << "Enter Value ['q' to stop]: ";
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
        << "\nOption (Uppercase): ";
        if (!(cin >> input)) {
            cout << "Invalid Input! Please input a single uppercase character.\n";
        }
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

[[nodiscard]] Sort<int>* getSortingAlgorithm() {
    char input = '\0';
    do {
        if (input) {
            cout << "The character you typed did not match the below options.\n";
        }
        cout << "Pick Your Sorting Algorithm:"
        << "\n\t'S': Selection Sort"
        << "\n\t'I': Insertion Sort"
        << "\n\t'B': Bubble Sort"
        << "\n============================"
        << "\nOption (Uppercase): ";
        if (!(cin >> input)) {
            cout << "Invalid Input! Please input a single uppercase character.\n";
        }
    } while (input != 'S' && input != 'I' && input != 'B');
    switch (input) {
        case 'S':
            return new SelectionSort<int>;
        case 'I':
            return new InsertionSort<int>;
        case 'B':
            return new BubbleSort<int>;
        default:
            return nullptr; // Make compiler happy
    }
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

template <class T, class Comparator = std::less<T>>
ostream& operator<<(ostream& o, const Sort<T, Comparator>& sort) { return o << sort.getName(); }

int main(int argc, char** argv)
{
    vector<int> data = getData();

    cout << "Original Data: " << data << endl;

    Sort<int>& sort = *getSortingAlgorithm();

    auto start = high_resolution_clock::now();

    sort(data);

    auto end = high_resolution_clock::now();

    duration<double> time_span = end - start;

    cout << "Sorted Data: " << data << endl;

    cout << "Running time for " << sort << " on a vector of " << data.size() << " ints: " << duration_cast<milliseconds>(time_span).count() << " ms" << endl;

    cout << "Number of comparisons: " << sort.getNumComparisons() << endl;

    if (!sort.testIfSorted(data)) {
        cerr << "Warning: The sorted sequence IS NOT sorted!\n";
    }

    return 0;
}
