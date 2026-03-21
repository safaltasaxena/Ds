#include <iostream>
using namespace std;

int fibbo(int a,int b,int n){


    if (n == 0)
        return a;
    if (n == 1)
        return b;
        
    return fibbo(b, a + b, n - 1);
        
}

int main () {

    int n;
    cin >> n;

    cout<<fibbo(0,1,n);

    return 0;

}