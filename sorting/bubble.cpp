//bubble sort,tc-o(n^2),sc-o(1),used when ith round ith largest at right place
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

for(int i=1;i<n;i++){
    bool swapped=false;//optimising for alr sorted array
    for(int j=0;j<n-i;j++){
        if(arr[j]>arr[j+1]){
            swap(arr[j],arr[j+1]);
            swapped=true;
        }
    }
    if(swapped==false){
        break;
    }
}

cout<<"sorted array"<<endl;
for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
}

return 0;
}
