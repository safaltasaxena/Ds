//constant window,when there is contsant size fixed window typa quest
//Q-get maxm sum of k consecutive integers.
//tc-o(n^2),sc-o(1)

#include <bits/stdc++.h>
using namespace std;

int MaxSum(int *arr,int n,int k){

    //l is for shrinking while r is for expansion always
    int l=0,r=k-1,sum=0;
    for(int i=0;i<=r;i++){
        sum+=arr[i];
    }

    int maxsum=sum;

    while(r<n){
        sum-=arr[l++];
        sum+=arr[r++];
        maxsum=max(maxsum,sum);
    }

    return maxsum;
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
cout<<"enter window size:"<<endl;
int k;
cin >> k;

cout<<"maxm sum:"<<MaxSum(arr,n,k);

return 0;

}
