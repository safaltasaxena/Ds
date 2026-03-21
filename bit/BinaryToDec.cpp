#include <bits/stdc++.h>
using namespace std;

int main(){
    string a;
    cin >> a;
    int sum=0;
    for(int i=0;i<a.size();i++){
        if(a[i]=='1'){
            sum+=pow(2,i);
        }
    }
    cout<<sum<<endl;
    return 0;
}