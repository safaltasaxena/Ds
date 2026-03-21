#include <iostream>
using namespace std;
//const long long MOD=1e+7;
int power(int a,int b){
    if(b==0) return 1;
    if(b==1) return a;

    int ans=power(a,b/2);
    if(b%2==0){
        return ans*ans;//%MOD
    }
    else{
        return a*ans*ans;//%MOD
    }
}


int main(){
    int a,b;
    cin >> a >> b;
    int ans=power(a,b);
    cout<<ans<<endl;
    return 0;
}