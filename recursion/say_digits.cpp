#include <iostream>
using namespace std;

void say(int n,string arr[]){

    if(n==0)
      return ;
    
    say(n/10,arr);
    cout<<arr[n%10]<<" ";

}

int main () {

    string arr[10]={"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
    
    int n;
    cin >> n;
    
    say(n,arr);

    return 0;

}