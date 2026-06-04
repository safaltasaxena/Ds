//kosaraju algo(directed graph) to find strongly connected components
//u start from any node in a ssc and then u do whatver but u will reach that node where u started from and u will be able to get to all other nodes of that ssc
//u should get to all nodes of that ssc and u should be able to get back to the starting node from all other nodes of that ssc
#include <bits/stdc++.h>
#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

class graph{
    public:
     unordered_map<int,vector<int>> adj;

     void addEdge(int u,int v){

        //create an edge from u to v
        adj[u].push_back(v);
    
     }
};

stack <int> s;

void topological_sort_helper_DFS(unordered_map<int,vector<int>>& adj, int node, unordered_map<int, bool> &visited) {
    visited[node] = true;

    for (auto neighbour : adj[node]) {
        if (!visited[neighbour]) {
            topological_sort_helper_DFS(adj, neighbour, visited);
        }
    }
    s.push(node); // push after visiting all neighbours

    return ;
}

void topological_sort_DFS(unordered_map<int, vector<int>> &adj,int n) {
    unordered_map<int, bool> visited;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            topological_sort_helper_DFS(adj, i, visited);
        }
    }
    return ;
}

void reverse_graph(unordered_map<int, vector<int>> &adj, unordered_map<int, vector<int>> &rev_adj,int n) {
    for (int i = 0; i < n; i++) {
        rev_adj[i]; // ensure node exists
    }
    for (auto nodePair : adj) {
        int node = nodePair.first;
        for (auto neighbour : nodePair.second) {
            rev_adj[neighbour].push_back(node); // reverse the edge
        }
    }

    return ;
}

void kosaraju_DFS(unordered_map<int, vector<int>>& rev_adj, int node, unordered_map<int, bool> &visited) {
    visited[node] = true;
    cout << node << " ";

    for (auto neighbour : rev_adj[node]) {
        if (!visited[neighbour]) {
            kosaraju_DFS(rev_adj, neighbour, visited);
        }
     }

    return ;
    
}

void kosaraju(unordered_map<int, vector<int>>& adj,int n){
    int com=0;
    topological_sort_DFS(adj,n);
    unordered_map<int, vector<int>> rev_adj;
    reverse_graph(adj, rev_adj, n);
    unordered_map<int, bool> visited;
    while(!s.empty()){
        int node=s.top();
        s.pop();
        if(!visited[node]){
            com++;
            kosaraju_DFS(rev_adj, node, visited);
            cout<<endl;
        }
    }
    cout<<"Number of strongly connected components: "<<com<<endl;
    return ;
}

int main () {
    int n;
    cout<<"Enter the number of nodes"<<endl;
    cin >>n; 

    graph g;

    cout<<"Enter the number of edges"<<endl;
    int m;
    cin>>m;

    cout<<"Enter the edges in the format: u v  (for directed graph)"<<endl;

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        //creating a directed graph
        g.addEdge(u,v);
    }

    cout<<"kosaraju's algorithm to find strongly connected components"<<endl;
    kosaraju(g.adj, n);

    return 0;

}

