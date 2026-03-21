#include <iostream>
using namespace std;

bool ls(int arr[],int n,int key){
     
    if(n==0)
       return false;
    
    if(arr[0]==key)
       return true;
    
    return ls(arr+1,n-1,key);
    
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
    
    cout<<"enter key: ";
    int key;
    cin >> key;

    if(ls(arr,n,key))
      cout<<"found";
    else
      cout<<"not found";

    return 0;

}