#include <iostream>
#include <cmath>

int jumpSearch(int arr[], int n, int key) {
    int step = sqrt(n); // Step size
    int prev = 0;

    // Jump in steps until finding a range where key might be present
    while (prev < n && arr[std::min(step, n) - 1] < key) {
        prev = step;
        step += sqrt(n);
        if (prev >= n) {
            return -1; // Element not found
        }
    }

    // Perform linear search in the identified block
    for (int i = prev; i < std::min(step, n); i++) {
        if (arr[i] == key) {
            return i; // Return index of key
        }
    }

    return -1; // If key is not found
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21}; // Sorted array
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 15;
    
    int result = jumpSearch(arr, n, key);
    if (result != -1) {
        std::cout << "Element found at index: " << result << std::endl;
    } else {
        std::cout << "Element not found" << std::endl;
    }

    return 0;
}