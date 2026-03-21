//binary search is for monotonous fnc only
//tc-o(logn)
#include <iostream>
using namespace std;

int bs(int k,int arr[],int n){
    
    int start=0;
    int end=n-1;

    /*int mid=(start+end)/2;
    optimizing the code so as to be in int range
    */

    int mid=start + (start-end)/2;

    while(start<=end){

        if(arr[mid]==k){
            return mid;
        }

        if(arr[mid]>k){
            end=mid-1;
        }

        else{
            start=mid+1;
        }

        mid=start + (start-end)/2;

    }

    return -1;

}

int main () {

    int n;
    cout<<"enter array size: ";
    cin >> n;

    int arr[n];
    cout<<"enter the array elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int k;
    cout<<"enter the value u wanna search: ";
    cin >> k;
    cout<<bs(k,arr,n);

    return 0;

}