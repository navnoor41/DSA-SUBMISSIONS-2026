#include<iostream>
using namespace std;
int main(){
    int arr[]={5,4,3,2,1};
    int n=sizeof(arr)/sizeof(int);
    
    for(int i=0;i<n-1;i++){
        int min=INT32_MAX;
        int minIndex=-1;
        for(int j=i;j<n;j++){
            if(arr[j]<min){
                min=arr[j];
                minIndex=j;
            }
        }
        int temp=arr[i];
        arr[i]=arr[minIndex];
        arr[minIndex]=temp;
     
    }
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}
