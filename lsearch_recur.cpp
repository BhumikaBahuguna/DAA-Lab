#include <iostream>
using namespace std;
int linearSearchRecursive(int a[], int n, int key, int index = 0) {
    // Base case: if index reaches n, key not found
    if (index == n) {
        return -1;
    }
    // If key is found at the current index, return the index
    if (a[index] == key) {
        return index;
    }
    // Recur for the next index
    return linearSearchRecursive(a, n, key, index + 1);
}
int main() {
    int a[50], n, key, res;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << "Enter key to search: ";
    cin >> key;
    
    res = linearSearchRecursive(a, n, key);
    if (res != -1) {
        cout << "Found at index " << res << endl;
    } else {
        cout << "Not found" << endl;
    }
    return 0;
}