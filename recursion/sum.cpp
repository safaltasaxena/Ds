//coudnt do on my own
#include <iostream>
using namespace std;

int Sum(int arr[],int n){

    // base cases
    if (n == 0)
        return 0;
    if (n == 1)
        return arr[0];

    int remainingPart = Sum(arr + 1, n - 1);
    int sum = arr[0] + remainingPart;
    return sum;
}


int main () {

    int n;
    cout<<"enter array size: ";
    cin >> n;

    int arr[n];
    cout<<"enter the array elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<Sum(arr,n);

    return 0;

}