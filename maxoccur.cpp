#include <iostream>
#include <vector>
using namespace std;
void findMaxOccurrenceCharacter(const vector<char>& arr) {
    int maxCount = 1;
    char maxChar = arr[0];
    bool hasDuplicate = false; 
    for (int i = 0; i < arr.size(); ++i) {
        int count = 0;       
        for (int j = 0; j < arr.size(); ++j) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }       
        if (count > maxCount) {
            maxCount = count;
            maxChar = arr[i];
            hasDuplicate = true;
        }
    }    
    if (maxCount == 1) {
        cout << "No Duplicates Present" << endl;
    } else {
        cout << maxChar << " - " << maxCount << endl;
    }
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
       
        vector<char> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        findMaxOccurrenceCharacter(arr);
    }
    
    return 0;
}
