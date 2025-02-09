#include <iostream>
using namespace std;

// Function to find a peak element using Binary Search
int findPeak(int arr[], int n) {
    int s = 0, e = n - 1;
    
    while (s < e) {
        int mid = (s + e) / 2;
        
        // Check if mid is a peak element
        if (arr[mid] > arr[mid + 1]) {
            e = mid;  // Move left
        } else {
            s = mid + 1;  // Move right
        }
    }
    
    return arr[s]; // Peak element found
}

int main() {
    int n;
    
    // Take input for size of array
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];

    // Input the array elements
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Find and print the peak element
    int ans = findPeak(arr, n);
    cout << "Peak Element: " << ans << endl;
    
    return 0;
}
