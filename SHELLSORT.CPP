#include <iostream>
using namespace std;

void shellSort(int arr[], int n) {

    // Start with a large gap and reduce it
    for (int gap = n / 2; gap > 0; gap /= 2) {

        // Perform insertion sort with this gap
        for (int i = gap; i < n; i++) {

            int temp = arr[i];
            int j = i;

            // Shift elements that are greater than temp
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j = j - gap;
            }

            // Put temp at its correct position
            arr[j] = temp;
        }
    }
}

int main() {
    int arr[] = {12, 34, 54, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    shellSort(arr, n);

    cout << "Sorted array: ";

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
