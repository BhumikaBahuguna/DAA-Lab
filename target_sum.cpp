#include <iostream>
#include <vector>

using namespace std;

void findTwoElementsWithSum(const vector<int>& arr, int key) {
    int n = arr.size();
    bool found = false;
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == key) {
                cout << arr[i] << " " << arr[j] << endl;
                found = true;
                break;
            }
        }
        if (found) break;
    }
    
    if (!found) {
        cout << "No Such Elements Exist" << endl;
    }
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int n;
        cin >> n;
        
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        int key;
        cin >> key;
        
        findTwoElementsWithSum(arr, key);
    }
    
    return 0;
}
