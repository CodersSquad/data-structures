#include <iostream>
#include <vector>

// Template function for sequential search
template <typename T>
int sequentialSearch(const std::vector<T>& arr, const T& target) {
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == target) {
            return i; // Return the index if target is found
        }
    }
    return -1; // Return -1 if target is not found
}

int main() {
    // Example with integers
    std::vector<int> intArr = {10, 20, 30, 40, 50};
    int targetInt = 30;
    int resultInt = sequentialSearch(intArr, targetInt);

    if (resultInt != -1) {
        std::cout << "Integer " << targetInt << " found at index: " << resultInt << std::endl;
    } else {
        std::cout << "Integer " << targetInt << " not found." << std::endl;
    }

    // Example with strings
    std::vector<std::string> stringArr = {"apple", "banana", "cherry", "date"};
    std::string targetString = "banana";
    int resultString = sequentialSearch(stringArr, targetString);

    if (resultString != -1) {
        std::cout << "String \"" << targetString << "\" found at index: " << resultString << std::endl;
    } else {
        std::cout << "String \"" << targetString << "\" not found." << std::endl;
    }

    // Example with a non-existent element
    int nonExistentInt = 60;
    int resultNonExistent = sequentialSearch(intArr, nonExistentInt);
    if (resultNonExistent != -1) {
        std::cout << "Integer " << nonExistentInt << " found at index: " << resultNonExistent << std::endl;
    } else {
        std::cout << "Integer " << nonExistentInt << " not found." << std::endl;
    }

    return 0;
}
