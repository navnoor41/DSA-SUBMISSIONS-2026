#include <iostream>
using namespace std;
 
int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(int);
 
    const int RANGE = 100;      // values lie in 0..99
    int bin[RANGE] = {0};       // one bin per possible value
 
    // Drop every element into its bin
    for (int i = 0; i < n; i++)
        bin[arr[i]]++;
 
    // Read the bins back in increasing order
    int index = 0;
    for (int v = 0; v < RANGE; v++) {
        while (bin[v] > 0) {
            arr[index++] = v;
            bin[v]--;
        }
    }
 
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
 
    return 0;
}
