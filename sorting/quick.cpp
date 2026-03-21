//quick sort,tc-o(nlogn),sc-o(n),preffered over merge sort
#include <bits/stdc++.h>
using namespace std;

int partition(int arr[],int s,int e){

    int pivot=arr[s];

    int cnt=0;
    for(int i=s+1;i<=e;i++){
        if(arr[i]<=pivot){
            cnt++;
        }
    }

    //place pivot at right pos
    int pivotIndex=s+cnt;
    swap(arr[pivotIndex],arr[s]);

    //left and right part(chote on left and bde on right wrt pivot)
    int i=s,j=e;

    while(i<pivotIndex && j>pivotIndex){
        
        while(arr[i]<pivot){
            i++;
        }

        while(arr[j]>pivot){
            j--;
        }

        if(i<pivotIndex && j>pivotIndex){
            swap(arr[i++],arr[j--]);
        }

    }

    return pivotIndex;
}

void quickSort(int arr[],int s,int e){
    
    //base case
    if(s>=e){
        return;
    }

    //partition
    int p=partition(arr,s,e);

    //left part sort
    quickSort(arr,s,p-1);

    //right part sort
    quickSort(arr,p+1,e);

}

int main() {

int n;
cout<<"enter size:"<<endl;
cin >> n;
int arr[n];
cout<<"enter array elements:"<<endl;
for(int i=0;i<n;i++){
    cin >> arr[i];
}

quickSort(arr,0,n-1);

cout<<"sorted array"<<endl;
for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
}

return 0;
}