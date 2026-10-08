#include<iostream>
using namespace std;
int main(){
    int arr[]={7,5,8,3,9,2,1,6};
    
    int n=sizeof(arr)/sizeof(int);
    for(int i=1;i<n;i++){
        int j=i;
        while(j>0 &&arr[j]<arr[j-1]){
        
                int temp=arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=temp;
                j--;
            }
        }
        
     
    
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}
