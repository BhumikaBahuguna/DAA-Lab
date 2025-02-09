#include <iostream>
#include <algorithm>
using namespace std;

// Function to check if we can place cows with at least `minDist` distance
bool canPlaceCows(int arr[], int n, int c, int minDist) {
    int count = 1;  // Place the first cow at the first stall
    int lastPlaced = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] - lastPlaced >= minDist) {
            count++;  // Place a cow here
            lastPlaced = arr[i];  // Update last placed position
            if (count == c) return true;  // All cows placed successfully
        }
    }
    return false;
}

// Function to find the maximum minimum distance
int aggressiveCows(int arr[], int n, int c) {
    sort(arr, arr + n);  // Step 1: Sort the stall positions

    int low = 1, high = arr[n - 1] - arr[0], ans = 0;

    // Binary search for the maximum possible minimum distance
    while (low <= high) {
        int mid = (low + high) / 2;

        if (canPlaceCows(arr, n, c, mid)) {
            ans = mid;   // Store the valid answer
            low = mid + 1;  // Try to increase the minimum distance
        } else {
            high = mid - 1; // Try a smaller minimum distance
        }
    }
    return ans;
}

// Main function
int main() {
    int n, c;
    cout << "Enter the number of stalls: ";
    cin >> n;
    int arr[n];
    cout << "Enter stall positions: ";
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << "Enter the number of cows: ";
    cin >> c;

    int result = aggressiveCows(arr, n, c);
    cout << "Maximum minimum distance: " << result << endl;
    
    return 0;
}
