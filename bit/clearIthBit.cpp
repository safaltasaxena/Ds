#include <bits/stdc++.h>
using namespace std;

int main(){
    int num;
    cin >> num;
    int bit;
    cin >> bit;
    num=num & ~(1<<bit);
    cout<<num;
    return 0;

}