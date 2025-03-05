#include <iostream>
#include <vector>
using namespace std;
string findMaxOccurrence(vector<char>& arr) {
    int freq[26] = {0};
    for (char ch : arr) {
        freq[ch - 'a']++;
    }
    int maxFreq = 0;
    char maxChar = '\0';
    for (int i = 0; i < 26; i++) {
        if (freq[i] > maxFreq) {
            maxFreq = freq[i];
            maxChar = 'a' + i;
        }
    }
    if (maxFreq == 1) {
        return "No Duplicates Present";
    }
    return string(1, maxChar) + " - " + to_string(maxFreq);
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
        cout << findMaxOccurrence(arr) << endl;
    }
    return 0;
}