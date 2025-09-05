#include <vector>
#include <iostream>
#include <algorithm> // For std::sort in main, not strictly part of binary search

template <typename T>
int binarySearch(const std::vector<T>& arr, const T& target) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2; // Avoids potential overflow compared to (low + high) / 2

        if (arr[mid] == target) {
            return mid; // Target found
        } else if (arr[mid] < target) {
            low = mid + 1; // Search in the right half
        } else {
            high = mid - 1; // Search in the left half
        }
    }
    return -1; // Target not found
}

// Example usage
#include <iostream>

int main() {
    std::vector<int> intVec = {10, 20, 30, 40, 50, 60};
    int targetInt = 40;
    int resultInt = binarySearch(intVec, targetInt);
    if (resultInt != -1) {
        std::cout << "Integer " << targetInt << " found at index: " << resultInt << std::endl;
    } else {
        std::cout << "Integer " << targetInt << " not found." << std::endl;
    }

    std::vector<double> doubleVec = {1.1, 2.2, 3.3, 4.4, 5.5};
    double targetDouble = 3.3;
    int resultDouble = binarySearch(doubleVec, targetDouble);
    if (resultDouble != -1) {
        std::cout << "Double " << targetDouble << " found at index: " << resultDouble << std::endl;
    } else {
        std::cout << "Double " << targetDouble << " not found." << std::endl;
    }

    return 0;
}
