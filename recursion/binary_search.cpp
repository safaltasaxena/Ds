//binary search using recursion
#include <iostream>
using namespace std;

bool bs(int k,int *arr,int s,int e){

    int mid=s+((e-s)/2);
    
    if(s<=e){

      if(arr[mid]==k)
         return true;
      else if(arr[mid]>k)
         return bs(k,arr,s,mid-1);
      else
         return bs(k,arr,mid+1,e);

    }

    else{
        return false;
    }   

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
    
    if(bs(k,arr,0,n-1))
       cout<<"found";
    else 
       cout<<"not found";

    return 0;

}