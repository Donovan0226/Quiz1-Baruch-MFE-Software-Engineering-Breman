#include <iostream>
using namespace std;

void swapInt(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

int partition(int arr[], int left, int right) {
    int pivot = arr[right];
    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            i++;
            swapInt(arr[i], arr[j]);
        }
    }
    swapInt(arr[i + 1], arr[right]);
    return i + 1;
}

void quickSort(int arr[], int left, int right) {
    if (left < right) {
        int p = partition(arr, left, right);
        quickSort(arr, left, p - 1);
        quickSort(arr, p + 1, right);
    }
}

// exampale of doing a quicksort, to see if the answer is correct
int main() {
    int arr[] = {9, 4, 7, 1, 3, 6, 2, 8, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
