#include <bits/stdc++.h>
using namespace std;

int main(){
    int num;
    cin >> num;
    int bit;
    cin >> bit;

    //left shift
    if(num & (1<<bit)==1){
         cout<<"Set";
    }
    else{
        "notSet";
    }

    //right shift
    if(((num>>bit) && 1)==1){
        cout<<"Set";
    }
    else{
        cout<<"notSet";
    }

    return 0;
}