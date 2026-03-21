#include <bits/stdc++.h>
using namespace std;

int main(){
    int num;
    cin >> num;
    string res;
    
    if(num == 0){
        cout << 0;
        return 0;
    }

    while(num){
        if(num%2==1) res+='1';
        else res+='0';
        num=num/2;
        
    }
    reverse(res.begin(),res.end());
    cout<<res<<endl;
    
    return 0;
}