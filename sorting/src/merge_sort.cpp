#include <iostream>
#include <vector>

// Merges two sorted subarrays into a single sorted array
void merge(std::vector<int>& arr, int low, int mid, int high) {
    std::vector<int> temp; // Temporary array for merging
    int left = low;        // Starting index of the left subarray
    int right = mid + 1;   // Starting index of the right subarray

    // Merge elements into the temporary array in sorted order
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // Copy any remaining elements from the left subarray
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    // Copy any remaining elements from the right subarray
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // Copy the sorted elements from the temporary array back to the original array
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

// Recursively divides the array and sorts subarrays
void mergeSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2; // Calculate the middle index

        // Recursively sort the left and right halves
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        // Merge the sorted halves
        merge(arr, low, mid, high);
    }
}

int main() {
    std::vector<int> arr = {12, 11, 13, 5, 6, 7};
    int n = arr.size();

    std::cout << "Original array: ";
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    mergeSort(arr, 0, n - 1);

    std::cout << "Sorted array: ";
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}
