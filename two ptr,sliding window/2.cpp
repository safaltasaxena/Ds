//longest subarray/substring where <condition>
//Q-lenght of the longest subarray with sum<=k
//tc-o(2N),sc-o(1)

//brtue force would be O(N^2) where 2 nested loops then for each existing array ull check

#include <bits/stdc++.h>
using namespace std;

int longest(int *arr,int n,int k){

    //l is for shrinking while r is for expansion always
    int l=0,r=0,sum=0,maxlen=0;

    while(r<n){

        sum+=arr[r];
        
        while(sum>k){
                sum-=arr[l];
                l++;
        }

        //optimized version-why to shrink it all the way shrink it upto how much maxlen u got so that is ans is greater than that okay if not then from smaller no to bigger no u will take time to reach
        /*
        if(sum>k){
                l++;
                sum-=arr[l];
        }
        here u would get tc as O(N)
        but if subarray they asked then u cant do it only for lentgh ques u can do this
        */

        if(sum<=k){
            maxlen=max(maxlen,r-l+1);
            //if subarray is asked then store l and r here
        }

        r++;

    }

    return maxlen;
    
}

int main() {

int n;
cout<<"enter size:"<<endl;
cin >> n;
int arr[n];
cout<<"enter array elements:"<<endl;
for(int i=0;i<n;i++){
    cin >> arr[i];
}

cout<<"enter condtion k:"<<endl;
int k;
cin >> k;

cout<<"lenght of the longest subarray with sum "<<k<<" is :"<<longest(arr,n,k)<<endl;

return 0;

}
