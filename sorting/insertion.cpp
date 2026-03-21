//insertion sort,tc-o(n^2),sc-o(1),used when ith smallest in ith round at right position
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
    int temp=arr[i];
    int j=i-1;
   for(j=i-1;j>=0;j--){
     if(arr[j]>temp){
        //shift
        arr[j+1]=arr[j];
     }
     else{
        //stop
        break;
     }
   }
   arr[j+1]=temp;
}

cout<<"sorted array"<<endl;
for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
}

return 0;
}
