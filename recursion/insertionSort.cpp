#include <iostream>
using namespace std;

void sortArray(int *arr,int s,int n){
    if(s==n) return ;
    int temp=arr[s];
    int i=s-1;
    for(i=s-1;i>=0;i--){
        if(temp<arr[i]){
            arr[i+1]=arr[i];
        }
        else{
            break;
        }
    }
    arr[i+1]=temp;
    sortArray(arr,s+1,n);
}

int main () {

    int arr[5]={2,5,1,6,9};
    sortArray(arr,1,4);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }


    return 0;
}