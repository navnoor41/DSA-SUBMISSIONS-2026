#include<iostream>
using namespace std;
int main(){
    int array[]={5,1,9,4,3,6};
    // int j;
    int i;
    int min=array[0];
    for( i=1;i<6;i++){
        if(array[i]<min){
        min=array[i];
        //  j=i;
        break;}
    }
    int temp=array[i];
    array[i]=array[5];
    array[5]=temp;
    for(int i=0;i<6;i++){
        cout<<array[i]<<" ";
    }
    
}
