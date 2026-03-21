//unordered is hash table ordered is bst so o(1) and o(logn) respectively.
#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main () {
      
    //creation
    unordered_map<string,int> m;
    
    //insertion
    
    //1
    pair<string,int> p = make_pair("safalta", 3);
    m.insert(p);

    //2
    pair<string,int> pair2("saxena", 2);
    m.insert(pair2);

    //3
    m["mera"] = 1;

    //it updates prev value is gone
    m["mera"] = 2;

    //search
    cout<<m["mera"]<<endl;
    cout<<m.at("safalta")<<endl;
    
    //over here it will give fault as there is no key as such
    //cout<<m.at("UNKNOWN_KEY")<<endl;

    //but now due to this a new key is created in the hashtable thus 0 would be printed here
    cout<<m["UNKOWN_KEY"]<<endl;

    //size
    cout<<m.size()<<endl;

    //to check presence,count gives 0 if absent else gives the count
    cout<<m.count("saxena")<<endl;

    //erase
    m.erase("saxena");
    cout<<m.size()<<endl;

    //iterator(1)
    for(auto i:m){
        cout<<i.first<<" "<<i.second<<endl;
    }

    //iterator(2)
    unordered_map <string,int> :: iterator it = m.begin();

    while(it != m.end()){
        cout<<it->first<<" "<<it->second<<endl;
        it++;
    }

    return 0;

}