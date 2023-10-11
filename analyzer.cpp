#include <iostream>
#include <chrono>
#include <vector>
#include <string>
#include "StringData.h"

//Partner: Joshua Brunk and Jackie Wang
//Nitish Goel
//COP 3504C Lab 05
//Source: old analyzer.py lab

int linear_search(std::vector<std::string>& container, std::string& element) { //linear search in C++!
    for (int i = 0; i < container.size(); i++) {
        if (container[i] == element) {
            return i;
        }
    }
    return -1;
}

int binary_search(std::vector<std::string>& container, std::string& element) { //binary search in C++
    int lower = 0;
    int higher = container.size() - 1;

    while (lower <= higher) {
        int middle = lower + (higher - lower) / 2;
        if (container[middle] == element) {
            return middle;
        } else if (container[middle] < element) {
            lower = middle + 1;
        } else {
            higher = middle - 1;
        }
    }
    return -1;
}

int main() {
    std::string target = "mmmmz"; //string to test
    std::vector<std::string> dataset = getStringData();

    auto start_time_linear = std::chrono::system_clock::now(); //measures time to run linear search
    int linear_result = linear_search(dataset, target);
    auto end_time_linear = std::chrono::system_clock::now();

    auto start_time_binary = std::chrono::system_clock::now(); //measures time to run binary search
    int binary_result = binary_search(dataset, target);
    auto end_time_binary = std::chrono::system_clock::now();

    auto linear_run_time = std::chrono::duration_cast<std::chrono::microseconds>(end_time_linear - start_time_linear);
    auto binary_run_time = std::chrono::duration_cast<std::chrono::microseconds>(end_time_binary - start_time_binary);

    std::cout << "Target: " << target << std::endl;
    std::cout << "Linear Search Result: " << linear_result << std::endl;
    std::cout << "Linear Search Time: " << linear_run_time.count() / 1000000.0 << " seconds" << std::endl;
    std::cout << "Binary Search Result: " << binary_result << std::endl;
    std::cout << "Binary Search Time: " << binary_run_time.count() / 1000000.0 << " seconds" << std::endl;

    return 0;
}
