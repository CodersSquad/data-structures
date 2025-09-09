#include <iostream>
#include <vector>
#include <algorithm> // Required for std::swap

void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    bool swapped; // Flag to check if any swaps occurred in a pass

    for (int i = 0; i < n - 1; ++i) {
        swapped = false; // Reset swapped flag for each pass
        for (int j = 0; j < n - 1 - i; ++j) {
            // Compare adjacent elements
            if (arr[j] > arr[j + 1]) {
                // Swap if they are in the wrong order
                std::swap(arr[j], arr[j + 1]);
                swapped = true; // Mark that a swap occurred
            }
        }
        // If no two elements were swapped in inner loop, then array is sorted
        if (swapped == false) {
            break;
        }
    }
}

void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> myVector = {64, 34, 25, 12, 22, 11, 90};

    std::cout << "Original array: ";
    printArray(myVector);

    bubbleSort(myVector);

    std::cout << "Sorted array: ";
    printArray(myVector);

    return 0;
}
