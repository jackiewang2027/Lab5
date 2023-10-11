// Name: Jackie Wang
// UFID: 69416910
// Worked with Nitish Glel and Joshua Brunk
#include <iostream>
#include <vector>
#include <chrono>
#include "StringData.h"

// A function that uses linear search (searching each element from the beginning
// to until it's found or the end of the container) by searching an iterable to get
// the index of where the element is or -1 if not found
int linear_search(const std::vector<std::string>& container, const std::string& element) {
    for (int i = 0; i < container.size(); ++i) {
        if (container[i] == element) {
            return i;
        }
    }
    return -1;
}
// Binary search algorithm inspired by ZyBooks Figure 9.8.1 Binary Search
int binary_search(const std::vector<std::string>& container, const std::string& element) {
    // Initialize Variables
    int num_lower = 0;
    int num_middle = 0;
    int num_higher = container.size() - 1;

    // A while loop that runs until num_lower is greater than num_higher
    // (when the list cannot be halved anymore to search for the element)
    while (num_higher >= num_lower) {
        // Find the middle of the list
        num_middle = (num_higher + num_lower) / 2;
        // Check if the element is either on the right or left half of the list
        if (container[num_middle] < element) {
            // Increase num_lower by 1 if the element is on the right half of the list
            num_lower = num_middle + 1;
        }
        else if (container[num_middle] > element) {
            // Decrease num_higher by 1 if the element is on the left half of the list
            num_higher = num_middle - 1;
        }
        else {
            // Returns if the element is at the middle of the list
            return num_middle;
        }
    }
    // Returns -1 if element is not found
    return -1;
}

int main() {
    std::vector<std::string> data = getStringData();

    std::cout << "Using linear search" << std::endl;
    auto start_time = std::chrono::high_resolution_clock::now();
    int index_result = linear_search(data, "not_here");
    std::cout << "Index: " << index_result << std::endl;
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_time = end_time - start_time;
    std::cout << "Linear search time to find \"not_here\": " << elapsed_time.count() << " seconds" << std::endl << std::endl;

    std::cout << "Using binary search" << std::endl;
    start_time = std::chrono::high_resolution_clock::now();
    index_result = binary_search(data, "not_here");
    std::cout << "Index: " << index_result << std::endl;
    end_time = std::chrono::high_resolution_clock::now();
    elapsed_time = end_time - start_time;
    std::cout << "Binary search time to find \"not_here\": " << elapsed_time.count() << " seconds" << std::endl << std::endl;

    std::cout << "Using linear search" << std::endl;
    start_time = std::chrono::high_resolution_clock::now();
    index_result = linear_search(data, "mzzzz");
    std::cout << "Index: " << index_result << std::endl;
    end_time = std::chrono::high_resolution_clock::now();
    elapsed_time = end_time - start_time;
    std::cout << "Linear search time to find \"mzzzz\": " << elapsed_time.count() << " seconds" << std::endl << std::endl;

    std::cout << "Using binary search" << std::endl;
    start_time = std::chrono::high_resolution_clock::now();
    index_result = binary_search(data, "mzzzz");
    std::cout << "Index: " << index_result << std::endl;
    end_time = std::chrono::high_resolution_clock::now();
    elapsed_time = end_time - start_time;
    std::cout << "Binary search time to find \"mzzzz\": " << elapsed_time.count() << " seconds" << std::endl << std::endl;

    std::cout << "Using linear search" << std::endl;
    start_time = std::chrono::high_resolution_clock::now();
    index_result = linear_search(data, "aaaaa");
    std::cout << "Index: " << index_result << std::endl;
    end_time = std::chrono::high_resolution_clock::now();
    elapsed_time = end_time - start_time;
    std::cout << "Linear search time to find \"aaaaa\": " << elapsed_time.count() << " seconds" << std::endl << std::endl;

    std::cout << "Using binary search" << std::endl;
    start_time = std::chrono::high_resolution_clock::now();
    index_result = binary_search(data, "aaaaa");
    std::cout << "Index: " << index_result << std::endl;
    end_time = std::chrono::high_resolution_clock::now();
    elapsed_time = end_time - start_time;
    std::cout << "Binary search time to find \"aaaaa\": " << elapsed_time.count() << " seconds" << std::endl;

    return 0;
}