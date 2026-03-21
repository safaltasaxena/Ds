#include <iostream>
using namespace std;

int fact (int n){

    //base case(nessecary)
    if(n==0){
        return 1;
    }
    //w/o base case segmentation fault it takes all values till stack overflow

    return n*fact(n-1);
    
    /*int smallerProblem=fact(n-1);
    int biggerProblem=n*smallerProblem;

    return biggerProblem;*/

}

int main () {

    cout<<"enter the num: "<<endl;
    int n;
    cin >> n;

    cout<<fact(n)<<endl;

    return 0;

}