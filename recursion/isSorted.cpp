#include <iostream>
using namespace std;

bool isSorted(int arr[],int n){
    
    if(n==1)
       return true;
    if(arr[n-1]>=arr[n-2])
       return isSorted(arr,n-1);
    return false;
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

    cout<<(isSorted(arr,n)?1:0);

    return 0;

}