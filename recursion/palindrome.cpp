#include <iostream>
using namespace std;

bool check(string& str,int i,int j){
    if(i>=j){
        return true;
    }
    if(str[i]!=str[j]){
        return false;
    }
    i++;
    j--;
    check(str,i,j);
}

int main(){

    string name="abbacbba";
    if(check(name,0,name.length()-1)){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    
    return 0;
}