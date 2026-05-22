#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

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


pair < int,vector <int> > shortest_path_Undirected_BFS(unordered_map<int, list<int>> &adj,int start,int end){
    vector <int> parent(adj.size(), -1); // to reconstruct path
    vector <int> distance(adj.size(), -1); // to store distances
    queue <int> q;
    vector <int> visited(adj.size(), 0); // to track visited nodes
    q.push(start);
    visited[start] = 1;
    distance[start] = 0; // distance to start node is 0
    parent[start] = start; // parent of start node is itself
    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (auto neighbour : adj[node]) {
            if (!visited[neighbour]) {
                visited[neighbour] = 1;
                parent[neighbour] = node; // set parent
                distance[neighbour] = distance[node] + 1; // set distance
                q.push(neighbour);
            }
        }

        if (node == end) {
            break; // stop BFS when we reach the end node
        }
    }

    return {distance[end], parent}; // return the distance and parent vector to reconstruct the path
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

    int start, end;
    cout<<"Enter the start and end nodes for shortest path calculation"<<endl;
    cin>>start>>end;

    pair <int, vector<int>> result = shortest_path_Undirected_BFS(g.adj, start, end);
    int distance = result.first;
    vector<int> parent = result.second;

    if (distance == -1) {
        cout << "No path exists between " << start << " and " << end << endl;
        return 0;
    } else {
        cout << "Shortest distance from " << start << " to " << end << " is: " << distance << endl;
        cout << "Path: ";
        vector<int> path;
        for (int v = end; v != start; v = parent[v]) {
            path.push_back(v);
        }
        path.push_back(start);
        reverse(path.begin(), path.end());
        for (int node : path) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;

}
