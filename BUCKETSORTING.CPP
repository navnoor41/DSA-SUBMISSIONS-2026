include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int arr[]={42,32,33,52,37,47,51};
    int n=sizeof(arr)/sizeof(int);

    int bucket[10][10];
    int count[10]={0};

    //Put elements into buckets
    for(int i=0;i<n;i++){
        int index=arr[i]/10;
        bucket[index][count[index]]=arr[i];
        count[index]++;
    }

    //Sort each bucket
    for(int i=0;i<10;i++){
        for(int j=0;j<count[i]-1;j++){
            for(int k=j+1;k<count[i];k++){
                if(bucket[i][j]>bucket[i][k])
                    swap(bucket[i][j],bucket[i][k]);
            }
        }
    }

    //Copy buckets back to array
    int index=0;

    for(int i=0;i<10;i++){
        for(int j=0;j<count[i];j++){
            arr[index]=bucket[i][j];
            index++;
        }
    }

    //Print sorted array
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

    return 0;
}
