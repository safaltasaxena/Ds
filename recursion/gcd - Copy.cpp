#include <iostream>
using namespace std;

int GCD(int a, int b){
        return (b)? GCD(b, a%b): a;
}

int main(){
    int a= GCD(18,6);
    cout<<a<<endl;
    return 0;
}