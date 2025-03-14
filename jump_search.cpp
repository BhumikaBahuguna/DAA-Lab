#include <stdio.h>

// Binary Search Function
void bSearch(int arr[], int low, int high, int k) {
    int mid, f = 0;
    
    while (low <= high) {  // Corrected condition
        mid = (low + high) / 2;
        
        if (arr[mid] == k) {
            f = 1;
            printf("Present %d", mid);
            return;
        }
        else if (arr[mid] < k) {
            low = mid + 1;  // Move right
        } 
        else {
            high = mid - 1; // Move left
        }
    }
    
    printf("Not Present");
}

// Exponential Search Function
void expoSearch(int arr[], int n, int k) {
    if (arr[0] == k) {
        printf("Present 0"); // Fixed index
        return;
    }
    
    int i = 1;
    while (i < n && arr[i] <= k) {
        i = i * 2;
    }

    // Perform binary search in the found range
    bSearch(arr, i / 2, (i < n) ? i : (n - 1), k);
}

// Main Function
int main() {
    int n, k, i;
    
    printf("Enter the size of array: ");
    scanf("%d", &n);
    
    int arr[n];
    
    printf("Enter array elements in sorted order:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter Key: ");
    scanf("%d", &k);
    
    expoSearch(arr, n, k);
    
    return 0;
}
