#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int jump_search(vector<int> list, int key) {
  int comparisons = 0;
  int n = list.size();
  int step = sqrt(n);
  int prev = 0;

  while (list[min(step, n) - 1] < key) {
    comparisons++;
    prev = step;
    step += sqrt(n);
    if (prev >= n) {
      cout << "Not Present ";
      return comparisons;
    }
  }

  while (list[prev] < key) {
    comparisons++;
    prev++;
    if (prev == min(step, n)) {
      cout << "Not Present ";
      return comparisons;
    }
  }

  if (list[prev] == key) {
    cout << "Present ";
    return comparisons;
  }

  cout << "Not Present ";
  return comparisons;
}

int main() {
  vector<int> list;
  int test_cases, size;
  cin >> test_cases;

  for (int i = 0; i < test_cases; i++) {
    cin >> size;
    list.resize(size);
    for (int j = 0; j < size; j++) {
      cin >> list[j];
    }

    int key;
    cin >> key;

    cout << jump_search(list, key) << endl;
  }
}