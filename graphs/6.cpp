//bellman ford algorithm
//why not dijkstra's algorithm?
//because dijkstra's algorithm doesn't work with negative weight edges, but bellman ford does
//why n-1 times?
//because in the worst case, the shortest path can have n-1 edges (in a graph with n nodes), so we need to relax all edges n-1 times to ensure we find the shortest path
/*
🌊 What Bellman-Ford is actually doing

Each iteration = “allow paths with one more edge”

Iteration meaning:
After 1st iteration → shortest paths using ≤ 1 edge
After 2nd iteration → shortest paths using ≤ 2 edges
...
After k iterations → shortest paths using ≤ k edges
*/

//===============================================================================================================

//floyd warshall algorithm
//At step k, you are allowed to use nodes {0…k} as intermediate nodes
/*
🌊 Iteration meaning in Floyd-Warshall
k = 0 → paths using node 0 as intermediate
k = 1 → paths using {0,1}
k = 2 → paths using {0,1,2}
...
k = n−1 → paths using all nodes

👉 After this:

You have considered all possible paths
*/
#include <bits/stdc++.h>
#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <climits>
#include <set>

using namespace std;

class graph{
    public:
     unordered_map<int,vector<pair<int,int>>> adj;

     void addEdge(int u,int v,int weight,bool dir){

        //create an edge from u to v
        adj[u].push_back({v, weight});
    
     }
};

int bellmanFord(unordered_map<int, vector<pair<int,int>>> &adj, int start, int end,int n) {
    vector <int> distance(n, INT_MAX); // to store shortest distances
    distance[start] = 0; // distance to start node is 0

    for (int i = 1; i <= n - 1; i++) { // relax edges repeatedly
        for (auto &node : adj) {
            int u = node.first;
            for (auto &neighbour : node.second) {
                int v = neighbour.first;
                int weight = neighbour.second;
                if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
                    distance[v] = distance[u] + weight; // update distance to v
                }
            }
        }
    }

    // Check for negative-weight cycles (optional)
    for (auto &node : adj) {
        int u = node.first;
        for (auto &neighbour : node.second) {
            int v = neighbour.first;
            int weight = neighbour.second;
            //“Did I improve after exhausting all edge-length paths?”
            //we use n-1 edges and now nth edge is left so we run one more iteration to check if we can still improve the distance, if we can then it means there is a negative weight cycle in the graph
             if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
                cout << "Graph contains a negative-weight cycle" << endl;
                return -1; // or handle as needed
            }
            if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
                cout << "Graph contains a negative-weight cycle" << endl;
                return -1; // or handle as needed
            }
        }
    }

    return distance[end]; // return the shortest distance to the end node

}

//floyd warshall algorithm
void floydWarshall(unordered_map<int, vector<pair<int,int>>> &adj, vector<vector<int>> &dist, int n) {

    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

    // distance to itself = 0
    for (int i = 0; i < n; i++) {
        dist[i][i] = 0;
    }

    for (auto &node : adj) {
        int u = node.first;
        for (auto &neighbour : node.second) {
            int v = neighbour.first;
            int weight = neighbour.second;

            dist[u][v] = min(dist[u][v], weight);
        }
    }
    
    // Floyd-Warshall algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j]; // update distance if a shorter path is found
                }
            }
        }
    }

    // Check for negative-weight cycles (optional)
    for (int i = 0; i < n; i++) {
        //over here if we do same as bellman ford to check for nth lets say but there is no nth left bcz we alr do all n nodes ite so its just recomputing the same discovered path as before nothing will affect or change
        //so we check for dist[i][i]<0 bcz this should be zero only ie no movment but after all nodes exlpore if u get negative value it means there is a negative weight cycle in the graph
        if (dist[i][i] < 0) {
            cout << "Graph contains a negative-weight cycle" << endl;
            return; // or handle as needed
        }
    }

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

    cout<<"Bellman-Ford Algorithm"<<endl;
    int src,dst;
    cout<<"enter source and destination nodes for shortest path calculation"<<endl;
    cin>>src>>dst;

    int result = bellmanFord(g.adj, src, dst, n);
    if(result == INT_MAX){
        cout<<"No path exists between "<<src<<" and "<<dst<<endl;
    }
    else{
        cout<<"Shortest distance from "<<src<<" to "<<dst<<" is: "<<result<<endl;
    }
    

    cout<<"Floyd Warshall Algorithm"<<endl;
    //floyd warshall algorithm
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
    floydWarshall(g.adj, dist, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INT_MAX) {
                cout << "distance " << i << " to " << j << ": " << "INF" << " ";
            } else {
                cout << "distance " << i << " to " << j << ": " << dist[i][j] << " ";
            }
        }
        cout << endl;
    }

    return 0;

}


