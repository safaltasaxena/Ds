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

template<typename T>
void BFS_cycle(unordered_map<T, list<T>> &adj) {
    unordered_map<T, bool> visited;
    list<T> q;
    unordered_map<T, T> parent; // to track parent of each node

    for (auto nodePair : adj) { // loop through all nodes in adjacency list
        T start = nodePair.first;

        if (!visited[start]) {
            // start BFS from this node
            visited[start] = true;
             parent[start] = start; // root's parent is itself
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
                    else if(neighbour != parent[node]) {
                        // if visited and not parent, cycle detected
                        cout << "Cycle detected at node: " << neighbour << endl;
                        return; // exit on cycle detection
                    }
                }
            }

           
        }
    }
    cout << "Cycle not detected" << endl;
    return; // exit no cycle deteted
}

template<typename T>
void dfsHelper(T node, unordered_map<T, list<T>> &adj, unordered_map<T, bool> &visited) {
    visited[node] = true;
    cout << node << " ";

    for (auto neighbour : adj[node]) {
        if (!visited[neighbour]) {
            dfsHelper(neighbour, adj, visited);
        }
    }
}

template<typename T>
void DFS(unordered_map<T, list<T>> &adj) {
    unordered_map<T, bool> visited;

    for (auto nodePair : adj) {  // handle disconnected graph
        T start = nodePair.first;

        if (!visited[start]) {
            dfsHelper(start, adj, visited);
            cout << endl; // separate components
        }
    }
}

template<typename T>
void dfsHelper_cycle(T node, unordered_map<T, list<T>> &adj, unordered_map<T, bool> &visited, unordered_map<T, T>& parent) {
    visited[node] = true;
    cout << node << " ";

    for (auto neighbour : adj[node]) {
        if (!visited[neighbour]) {
            parent[neighbour] = node;
            dfsHelper_cycle(neighbour, adj, visited, parent);
        }
        else if(neighbour != parent[node]) {
            // if visited and not parent, cycle detected
            cout << "Cycle detected at node: " << neighbour << endl;
            return; // exit on cycle detection
        }
    }
}

template<typename T>
void DFS_cycle(unordered_map<T, list<T>> &adj) {
    unordered_map<T, bool> visited;
    unordered_map<T, T> parent; // to track parent of each node


    for (auto nodePair : adj) {  // handle disconnected graph
        T start = nodePair.first;

        if (!visited[start]) {
            dfsHelper_cycle(start, adj, visited, parent);
            parent[start] = start; // root's parent is itself
            cout << endl; // separate components
        }
    }
    cout << "Cycle not detected" << endl;
    return; // exit no cycle deteted
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
    
    cout << "BFS Traversal:" << endl;
    BFS(g.adj);

    cout << "DFS Traversal:" << endl;
    DFS(g.adj);

    cout<< "Cycle Detection using BFS:" << endl;
    BFS_cycle(g.adj);



    return 0;

}