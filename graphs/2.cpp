//creation and implementation,BFS
#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <stack>
#include <vector>

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
int flag =0;
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
            flag=1;
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
            if (DFS_helper_directed_cycle(adj, start, visited, dfs_path)) {
                cout << "Cycle detected" << endl;
                return;
            }
        }
    }

    cout << "Cycle not detected" << endl;   
}   

template<typename T>
void BFS_directed_cycle(unordered_map<T, list<T>> &adj) {
    unordered_map<T, int> indegree;
    for (auto nodePair : adj) {
        T node = nodePair.first;
        if (indegree.find(node) == indegree.end()) {
            indegree[node] = 0; // initialize indegree for all nodes
        }
        for (auto neighbour : nodePair.second) {
            indegree[neighbour]++; // calculate indegree
        }
    }

    queue<T> q;
    for (auto nodeIndegree : indegree) {
        if (nodeIndegree.second == 0) {
            q.push(nodeIndegree.first); // enqueue nodes with zero indegree
        }
    }

    int visited_count = 0;
    while (!q.empty()) {
        T node = q.front();
        q.pop();
        visited_count++;

        for (auto neighbour : adj[node]) {
            indegree[neighbour]--; // decrease indegree of neighbours
            if (indegree[neighbour] == 0) {
                q.push(neighbour); // enqueue if indegree becomes zero
            }
        }
    }

    if (visited_count != adj.size()) {
        cout << "Cycle detected" << endl;
    } else {
        cout << "Cycle not detected" << endl;
    }
}


void topological_sort_helper_DFS(unordered_map<int, list<int>> &adj, int node, unordered_map<int, bool> &visited, stack <int> &s) {
    visited[node] = true;

    for (auto neighbour : adj[node]) {
        if (!visited[neighbour]) {
            topological_sort_helper_DFS(adj, neighbour, visited, s);
        }
    }
    s.push(node); // push after visiting all neighbours
}

vector <int> topological_sort_DFS(unordered_map<int, list<int>> &adj) {
    unordered_map<int, bool> visited;
    list<int> ordering; // to store topological order
    stack <int> s;
    for (auto nodePair : adj) { // loop through all nodes in adjacency list
        int start = nodePair.first;

        if (!visited[start]) {
            // start DFS from this node
            topological_sort_helper_DFS(adj, start, visited, s);
        }
    }
    vector <int> topo_order;
    while(!s.empty()) {
        topo_order.push_back(s.top());
        s.pop();
    }
    return topo_order;
}
//topo sort does NOT say leaf must be last

vector <int> topological_sort_BFS(unordered_map<int, list<int>> &adj) {
    unordered_map<int, int> indegree;
    for (auto nodePair : adj) {
        int node = nodePair.first;
        if (indegree.find(node) == indegree.end()) {
            indegree[node] = 0; // initialize indegree for all nodes
        }
        for (auto neighbour : nodePair.second) {
            indegree[neighbour]++; // calculate indegree
        }
    }

    queue <int> q;
    for (auto nodeIndegree : indegree) {
        if (nodeIndegree.second == 0) {
            q.push(nodeIndegree.first); // enqueue nodes with zero indegree
        }
    }

    vector <int> topo_order;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topo_order.push_back(node); // add to topological order

        for (auto neighbour : adj[node]) {
            indegree[neighbour]--; // decrease indegree of neighbours
            if (indegree[neighbour] == 0) {
                q.push(neighbour); // enqueue if indegree becomes zero
            }
        }
    }

    if (topo_order.size() != adj.size()) {
        cout << "Cycle detected, topological sort not possible" << endl;
        return {}; // return empty if cycle detected
    }

    return topo_order;
}

//topo sort only works for directed acyclic graphs (DAGs)
/*
DFS = push after children
DFS = build answer backward (postorder)
BFS = push when no parents left
BFS = build answer forward (indegree 0 first)
*/

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

    cout<<"BFS for directed graph cycle detection: "<<endl;
    BFS_directed_cycle(g.adj);
   
    cout<<"Topological sort DFS: "<<endl;
    vector <int> topo_order = topological_sort_DFS(g.adj);
    for (int node : topo_order) {
        cout << node << " ";
    }
    cout << endl;

    cout<<"Topological sort BFS: "<<endl;
    vector <int> topo_order_bfs = topological_sort_BFS(g.adj);
    for (int node : topo_order_bfs) {
        cout << node << " ";
    }
    cout << endl;

    return 0;

}