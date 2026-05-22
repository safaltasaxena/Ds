#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <climits>

/*

🔹 Key property of DAG
No cycles → no going back
This is HUGE.

Before processing node v,
ALL nodes that can reach v are already processed

🔥 Why this solves everything
When you reach a node:
👉 You already know the best way to reach it
👉 So you can safely propagate forward

*/
using namespace std;

class graph{
    public:
     unordered_map<int,vector<pair<int,int>>> adj;

     void addEdge(int u,int v,int weight,bool dir){

        //create an edge from u to v
        adj[u].push_back({v, weight});
    
     }

     void print(){
        for(auto i:adj){
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<j.first<<"("<<j.second<<"), ";
            }
            cout<<endl;
        }
     }

};


void topological_sort_helper_DFS(unordered_map<int, vector<pair<int,int>>> &adj, int node, unordered_map<int, bool> &visited, stack <int> &s) {
    visited[node] = true;

    for (auto neighbour : adj[node]) {
        if (!visited[neighbour.first]) {
            topological_sort_helper_DFS(adj, neighbour.first, visited, s);

        }
    }
    s.push(node); // push after visiting all neighbours
}

pair <int, vector<pair<int,int>> > shortest_path_Directed_weighted_DFS(unordered_map<int, vector<pair<int,int>>> &adj, int start, int end,int n) {
    unordered_map<int, bool> visited;
    stack <int> s;
    for (int i = 0; i < n; i++) { // loop through all nodes in adjacency list
        int node = i;

        if (!visited[node]) {
            // start DFS from this node
            topological_sort_helper_DFS(adj, node, visited, s);
        }
    }
    vector <int> distance(n, INT_MAX); // to store shortest distances
    vector <pair<int,int>> parent(n, {-1, -1}); // to reconstruct path
    distance[start] = 0; // distance to start node is 0
    parent[start] = {start, 0}; // parent of start node is itself

    while(!s.empty()) {
        int node = s.top();
        s.pop();

        if (distance[node] != INT_MAX) { // only process reachable nodes
            for (auto neighbour : adj[node]) {
                int v = neighbour.first;
                int weight = neighbour.second;
                if (distance[node] + weight < distance[v]) {
                    distance[v] = distance[node] + weight; // relax edge
                    parent[v] = {node, weight}; // set parent for path reconstruction
                }
            }
        }
    }
    return {distance[end], parent};
}


int main () {
    
    int n;
    cout<<"Enter the number of nodes"<<endl;
    cin >>n; 

    graph g;

    cout<<"Enter the number of edges"<<endl;
    int m;
    cin>>m;

    cout<<"Enter the edges in the format: u v weight (for directed graph)"<<endl;

    for(int i=0;i<m;i++){
        int u,v,weight;
        cin>>u>>v>>weight;
        //creating a directed graph
        g.addEdge(u,v,weight,1);
    }

    g.print();
    cout<<endl;

    cout<<"enter start and end nodes for shortest path calculation"<<endl;
    int start, end;
    cin>>start>>end;
    auto result = shortest_path_Directed_weighted_DFS(g.adj,start, end,n);

    if(result.first == INT_MAX){
        cout<<"No path exists between "<<start<<" and "<<end<<endl;
    }
    else{
        cout<<"Shortest distance from "<<start<<" to "<<end<<" is: "<<result.first<<endl;
        cout<<"Path: ";
        vector<int> path;
        for (int v = end; v != start; v = result.second[v].first) {
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