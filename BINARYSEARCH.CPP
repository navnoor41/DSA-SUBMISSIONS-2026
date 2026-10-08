#include<iostream>
using namespace std;
int main(){
    int arr[]={1,5,7,9,10,12,14,17,19,22};
    int n=sizeof(arr)/sizeof(int);
    int low=0,high=n-1,Index=-1;
    int target;
    cin>>target;
    while(low<=high){
    int mid=low+(high-low)/2;
    if(arr[mid]==target) {
    Index=mid;
    break;
}
    else if(arr[mid]>target) high=mid-1;
    else low=mid+1;
    }
    if(Index==-1)
    cout<<"Target Not found";
    else 
    cout<<" target found at Index : "<<Index<<endl;
}
