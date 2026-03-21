//recursion over choices
#include <iostream>
#include <vector>
using namespace std;

void solve(int *nums,int n,vector <int> empty,int index,vector <vector<int>>& ans){

    if(index>=n){
        ans.push_back(empty);
        return;
    }
    
    //exclude
    solve(nums,n,empty,index+1,ans);
    
    //include
    int element=nums[index];
    empty.push_back(element);
    solve(nums,n,empty,index+1,ans);

}

int main () {
    int nums[3]={1,2,3};
    int n=3;
    vector <vector <int>> ans;
    int index=0;
    vector <int> empty;
    solve(nums,n,empty,index,ans);
    cout<<"{";
    for (auto subset : ans) {
    cout << "{ ";
    for (int x : subset) {
        cout << x << ",";
    }
    cout << "}";
    }
    cout<<"}";
    return 0;
}