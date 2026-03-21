//selection sort,tc-o(n^2),sc-o(1),used for small sized arrays
#include <bits/stdc++.h>
using namespace std;

int main() {

int n;
cout<<"enter size:"<<endl;
cin >> n;
vector <int> arr(n);
cout<<"enter array elements:"<<endl;
for(int i=0;i<n;i++){
    cin >> arr[i];
}

for(int i=0;i<n-1;i++){
    int minindex=i;
    for(int j=i+1;j<n;j++){
        if(arr[minindex]>arr[j]){
            minindex=j;
        }
    }
    swap(arr[i],arr[minindex]);
}

cout<<"sorted array"<<endl;
for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
}

return 0;
}
