#include <iostream>
using namespace std;

void sortArray(int *arr,int s,int n){
    if(s==n) return;
    int minindex=s;
    for(int i=s+1;i<n;i++){
        if(arr[minindex]>arr[i]){
            swap(arr[minindex],arr[i]);
        }
    }
    sortArray(arr,s+1,n);

}

int main () {

    int arr[5]={2,5,1,6,9};
    sortArray(arr,0,4);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }


    return 0;
}