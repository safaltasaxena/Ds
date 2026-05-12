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
bool DFS_helper_directed_cycle(unordered_map<T, list<T>> &adj, T node, unordered_map<T, bool> &visited, unordered_map<T, bool> &dfs_path) {

    visited[node] = true;
    dfs_path[node] = true; // mark node in current DFS path
    
    for (auto neighbour : adj[node]) {
        if (!visited[neighbour]) {
            if (DFS_helper_directed_cycle(adj, neighbour, visited, dfs_path)) {
                return true; // cycle detected in deeper call
            }
        } else if (dfs_path[neighbour]) {
            cout << "Cycle detected at node: " << neighbour << endl;
            return true; // cycle detected
        }
    } 
    dfs_path[node] = false; // backtrack: unmark node from current DFS path
    return false; // no cycle detected in this path  

}
template<typename T>
void DFS_directed_cycle(unordered_map<T, list<T>> &adj) {
    unordered_map<T, bool> visited; 
    unordered_map<T, bool> dfs_path; // to track nodes in the current DFS path

    for (auto nodePair : adj) {  // handle disconnected graph
        T start = nodePair.first;

        if (!visited[start]) {
            DFS_helper_directed_cycle(adj, start, visited, dfs_path);
        }
    }

    cout << "Cycle not detected" << endl;   
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
        g.addEdge(u,v,1);
    }

    g.print();
    cout<<endl;
    
    cout<<"DFS for directed graph cycle detection: "<<endl;
    DFS_directed_cycle(g.adj);


    return 0;

}