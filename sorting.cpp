#include <bits/stdc++.h>
using namespace std;

class SortingAlgorithms {
public:
    static void bubble_sort(int *arr, int n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]); // Use std::swap instead of swap(&a, &b) which is incorrect
                }
            }
        }
    }

    static void modified_bubble_sort(int *arr, int n) {
        for (int i = 0; i < n; i++) {
            int swapc = 0; // Typo fixed: was swpc
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                    swapc++;
                }
            }
            if (swapc == 0)
                break;
        }
    }

    static void selection_sort(int *arr, int n) {
        for (int i = 0; i < n; i++) {
            int min = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[min]) {
                    min = j;
                }
            }
            if (i != min) // This was inside inner loop mistakenly
                swap(arr[min], arr[i]);
        }
    }

    static void insertion_sort(int *arr, int n) {
        for (int i = 1; i < n; i++) {
            int temp = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > temp) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = temp;
        }
    }

    static void merge(int *arr, int l, int mid, int r) {
        int n1 = mid - l + 1;
        int n2 = r - mid;
        int *L = new int[n1];
        int *R = new int[n2];

        for (int i = 0; i < n1; i++)
            L[i] = arr[l + i];
        for (int i = 0; i < n2; i++)
            R[i] = arr[mid + 1 + i];

        int i = 0, j = 0, k = l;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j])
                arr[k++] = L[i++];
            else
                arr[k++] = R[j++];
        }
        while (i < n1)
            arr[k++] = L[i++];
        while (j < n2)
            arr[k++] = R[j++];

        delete[] L;
        delete[] R;
    }

    static void merge_sort(int *arr, int l, int r) {
        if (l < r) {
            int mid = l + (r - l) / 2;
            merge_sort(arr, l, mid);
            merge_sort(arr, mid + 1, r);
            merge(arr, l, mid, r);
        }
    }

    static int partition(int *arr, int l, int r) {
        int pivot = arr[r];
        int i = l - 1;
        for (int j = l; j < r; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[r]);
        return i + 1;
    }

    static void quick_sort(int *arr, int l, int r) {
        if (l < r) {
            int p = partition(arr, l, r);
            quick_sort(arr, l, p - 1);
            quick_sort(arr, p + 1, r);
        }
    }

    static int randomized_partition(int *arr, int l, int r) {
        srand(time(0));
        int random_index = l + rand() % (r - l + 1);
        swap(arr[random_index], arr[r]);
        return partition(arr, l, r);
    }

    static void randomized_quick_sort(int *arr, int l, int r) {
        if (l < r) {
            int p = randomized_partition(arr, l, r);
            randomized_quick_sort(arr, l, p - 1);
            randomized_quick_sort(arr, p + 1, r);
        }
    }

    static void heapify(int *arr, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[left] > arr[largest])
            largest = left;
        if (right < n && arr[right] > arr[largest])
            largest = right;

        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }

    static void build_heap(int *arr, int n) {
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }
    }

    static void heap_sort(int *arr, int n) {
        build_heap(arr, n);
        for (int i = n - 1; i > 0; i--) {
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }

    static void count_sort(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return;

        int max_val = *max_element(arr.begin(), arr.end());
        vector<int> freq(max_val + 1, 0);
        vector<int> sol(n);

        for (int i = 0; i < n; i++) {
            freq[arr[i]]++;
        }

        for (int i = 1; i <= max_val; i++) {
            freq[i] += freq[i - 1];
        }

        for (int i = n - 1; i >= 0; i--) {
            sol[freq[arr[i]] - 1] = arr[i];
            freq[arr[i]]--;
        }

        for (int i = 0; i < n; i++) {
            arr[i] = sol[i];
        }
    }
};
void printArray(const vector<int>& arr) {
    for (int val : arr)
        cout << val << " ";
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> original(n);
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> original[i];
    }

    vector<int> arr;

    // Bubble Sort
    arr = original;
    SortingAlgorithms::bubble_sort(arr.data(), arr.size());
    cout << "Bubble Sort: ";
    printArray(arr);

    // Modified Bubble Sort
    arr = original;
    SortingAlgorithms::modified_bubble_sort(arr.data(), arr.size());
    cout << "Modified Bubble Sort: ";
    printArray(arr);

    // Selection Sort
    arr = original;
    SortingAlgorithms::selection_sort(arr.data(), arr.size());
    cout << "Selection Sort: ";
    printArray(arr);

    // Insertion Sort
    arr = original;
    SortingAlgorithms::insertion_sort(arr.data(), arr.size());
    cout << "Insertion Sort: ";
    printArray(arr);

    // Merge Sort
    arr = original;
    SortingAlgorithms::merge_sort(arr.data(), 0, arr.size() - 1);
    cout << "Merge Sort: ";
    printArray(arr);

    // Quick Sort
    arr = original;
    SortingAlgorithms::quick_sort(arr.data(), 0, arr.size() - 1);
    cout << "Quick Sort: ";
    printArray(arr);

    // Randomized Quick Sort
    arr = original;
    SortingAlgorithms::randomized_quick_sort(arr.data(), 0, arr.size() - 1);
    cout << "Randomized Quick Sort: ";
    printArray(arr);

    // Heap Sort
    arr = original;
    SortingAlgorithms::heap_sort(arr.data(), arr.size());
    cout << "Heap Sort: ";
    printArray(arr);

    // Count Sort (vector-based, no change)
    arr = original;
    SortingAlgorithms::count_sort(arr);
    cout << "Count Sort: ";
    printArray(arr);

    return 0;
}
