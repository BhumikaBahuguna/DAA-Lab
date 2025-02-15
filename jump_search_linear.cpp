#include <iostream>
#include <cmath>

using namespace std;

void linearSearch(int arr[], int start, int end, int key) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == key) {
            cout << "Present " << i << endl;
            return;
        }
    }
    cout << "Not Present" << endl;
}

void jumpSearch(int arr[], int n, int key) {
    if (arr[0] == key) {
        cout << "Present 0" << endl;
        return;
    }

    int step = sqrt(n); // Step size
    int prev = 0;

    // Jump in steps until finding a range where key might be present
    while (prev < n && arr[min(step, n) - 1] < key) {
        prev = step;
        step += sqrt(n);
        if (prev >= n) {
            cout << "Not Present" << endl;
            return;
        }
    }

    // Perform linear search in the identified block
    linearSearch(arr, prev, min(step, n) - 1, key);
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21}; // Sorted array
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 15;
    
    jumpSearch(arr, n, key);

    return 0;
}