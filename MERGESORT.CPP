#include <iostream>
using namespace std;

void merge(int arr[], int start, int mid, int end) {

    int i = start;
    int j = mid + 1;
    int k = 0;

    int c[100];  // temporary array

    // Compare elements of both halves
    while (i <= mid && j <= end) {

        if (arr[i] < arr[j]) {
            c[k] = arr[i];
            i++;
        }
        else {
            c[k] = arr[j];
            j++;
        }

        k++;
    }

    // Remaining elements in left half
    while (i <= mid) {
        c[k] = arr[i];
        i++;
        k++;
    }

    // Remaining elements in right half
    while (j <= end) {
        c[k] = arr[j];
        j++;
        k++;
    }

    // Copy sorted elements back to original array
    for (int i = start, k = 0; i <= end; i++, k++) {
        arr[i] = c[k];
    }
}


void MergeSort(int arr[], int start, int end) {

    // Base condition
    if (start >= end) {
        return;
    }

    int mid = start + (end - start) / 2;

    // Divide
    MergeSort(arr, start, mid);
    MergeSort(arr, mid + 1, end);

    // Merge
    merge(arr, start, mid, end);
}


int main() {

    int arr[] = {30, 12, 9, 55, 23, 77, 11, 90};

    int n = sizeof(arr) / sizeof(int);

    MergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
