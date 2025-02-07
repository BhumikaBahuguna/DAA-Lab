#include<iostream>
using namespace std;
int linearsearch(int a[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (a[i] == key) {
            return i; // Return the index where the key is found
        }
    }
    return -1; // Return -1 if the key is not found
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
    res = linearsearch(a, n, key);
    if (res != -1) {
        cout << "Found at index " << res << endl;
    } else {
        cout << "Not found" << endl;
    }
    return 0;
}
