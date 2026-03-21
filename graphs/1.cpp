//creation and implementation,BFS
#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

template<typename T>
class graph{
    public:
     unordered_map<T,list<T>> adj;

     void addEdge(T u,T v,bool dir){
        //direction=0->undirected
        //dir=1->directed

        //create an edge from u to v
        adj[u].push_back(v);

        if(dir==0){
            adj[v].push_back(u);
        }
     }

     void print(){
        for(auto i:adj){
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<j<<", ";
            }
            cout<<endl;
        }
     }

};


template<typename T>
void BFS(unordered_map<T, list<T>> &adj) {
    unordered_map<T, bool> visited;
    list<T> q;

    for (auto nodePair : adj) { // loop through all nodes in adjacency list
        T start = nodePair.first;

        if (!visited[start]) {
            // start BFS from this node
            visited[start] = true;
            q.push_back(start);

            while (!q.empty()) {
                T node = q.front();
                q.pop_front();
                cout << node << " ";

                for (auto neighbour : adj[node]) {
                    if (!visited[neighbour]) {
                        visited[neighbour] = true;
                        q.push_back(neighbour);
                    }
                }
            }

            cout << endl; // separates components
        }
    }
}


int main () {
    
    int n;
    cout<<"Enter the number of nodes"<<endl;
    cin >>n; 

    int m;
    cout<<"Enter the number of edges"<<endl;
    cin>>m;

    graph<int> g;

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        //creating an undirected graph
        g.addEdge(u,v,0);
    }

    g.print();
    cout<<endl;

    BFS(g.adj);

    return 0;

}