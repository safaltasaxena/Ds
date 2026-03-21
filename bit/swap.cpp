#include <bits/stdc++.h>
using namespace std;

int main(){

    int a,b;
    cin >> a >> b;
    cout<<"a:"<<a<<" b:"<<b;

    //xor usecase to swap
    a=a^b;
    b=a^b;
    a=a^b;

    cout<<"a:"<<a<<" b:"<<b;

    return 0;
}