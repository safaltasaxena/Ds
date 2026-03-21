#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int num=n;

    //brute force
    int  cnt=0; 
    while(n>1){
       cnt+=n&1;
       n=n>>1;
    }
    if(n==1)cnt+=1;
    cout<<cnt<<endl;

    //method2
    int cnt1=0;
    while(num>0){
        num=num&num-1;
        cnt1++;
    }
    cout<<cnt1<<endl;


    return 0;
}