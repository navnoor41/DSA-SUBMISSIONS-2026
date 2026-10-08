#include <iostream>
using namespace std;

int Partition(int arr[], int i, int j) {
 int pivot = arr[i];
    int start = i;
    int end = j;

    while (start<end) {

        while (arr[start] <= pivot) {
            start++;
        }

        while (arr[end]>pivot) {
            end--;
        }

        if (start<end) {
            swap(arr[start], arr[end]);
        }
    }

    swap(arr[i], arr[end]);

    return end;
}


void quickSort(int arr[], int i, int j) {

    if (i<j) {

        int pivotIndex = Partition(arr, i, j);
        quickSort(arr, i, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, j);
    }
}


int main() {

    int arr[] = {30, 12, 9, 55, 23, 77, 11, 90};
    int n = sizeof(arr) / sizeof(int);
    quickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
