#include <iostream>
#include <vector>
using namespace std;
#define Max 100
int main() {
  vector<int> arr;
  int m;
  cin >> m;
  for (int j = 0; j < m; j++) {
        int f=0;
    int n;
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++)
      cin >> arr[i];
    for (int i = n - 1; i > 0; i--) {
      int j = 0;
      int k = i - 1;
      while (j < k) {
        if ((arr[j] + arr[k]) == arr[i]) {
          cout << j+1 << " , " << k+1 << " , " << i+1 << endl;
          f=1;
          break;
          j++;
          k--;
        } else if ((arr[j] + arr[k]) > arr[i]) {
          k--;
        } else {
          j++;
        }
      }
      if(f==1)
        break;
    }
    if(f!=1)
        cout<<"No sequence";
  }
  return 0;
}