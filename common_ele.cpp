#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;
void findCommonElements(vector<int>& arr1, vector<int>& arr2) {
    int i = 0, j = 0;
    vector<int> commonElements;
    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] == arr2[j]) {
            commonElements.push_back(arr1[i]);
            i++; j++; 
        } 
        else if (arr1[i] < arr2[j]) {
            i++; 
        } 
        else {
            j++; 
        }
    }
    for (int num : commonElements) {
        cout << num << " ";
    }
    cout << endl;
}
int main() {
    int m, n;
    cin >> m;
    vector<int> arr1(m);
    for (int i = 0; i < m; i++) {
        cin >> arr1[i];
    }
    cin >> n;
    vector<int> arr2(n);
    for (int i = 0; i < n; i++) {
        cin >> arr2[i];
    }
    findCommonElements(arr1, arr2);
    return 0;
}
