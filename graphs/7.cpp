///mst-it is a tree where n nodes and n-1 edges and all nodes are connected this coems from graph
//

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

     void addEdge(int u,int v,int weight){

        //create an edge from u to v
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});
    
     }
};

//PRIM'S ALGORITHM
void MST_Prim(unordered_map<int, vector<pair<int,int>>> &adj, int start, int n) {
    vector <int> parent(n, -1); // to store the parent of each node in the MST
    vector <int> key(n, INT_MAX); // to store the minimum weight edge for each node
    vector <bool> inMST(n, false); // to track if a node is included in MST

    /*
    key[start] = 0; // start from the given node
    parent[start] = -1; // start node has no parent

    for (int count = 0; count < n - 1; count++) {
        int minKey = INT_MAX, minIndex;

        // Find the vertex with the minimum key value
        for (int v = 0; v < n; v++) {
            if (!inMST[v] && key[v] < minKey) {
                minKey = key[v];
                minIndex = v;
            }
        }

        inMST[minIndex] = true; // Add the vertex to the MST

        // Update the key value and parent index of the adjacent vertices of the picked vertex
        for (auto &neighbour : adj[minIndex]) {
            int v = neighbour.first;
            int weight = neighbour.second;
            if (!inMST[v] && weight < key[v]) {
                parent[v] = minIndex;
                key[v] = weight;
            }
        }
    }
        */

    // Using a priority queue to optimize the selection of the minimum key vertex
    // min heap: {key, node}
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    key[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (inMST[u]) continue; // skip if already taken

        inMST[u] = true;

        for (auto &nbr : adj[u]) {
            int v = nbr.first;
            int wt = nbr.second;

            if (!inMST[v] && wt < key[v]) {
                key[v] = wt;
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }

    // Print the edges of the MST
    cout << "Edge \tWeight" << endl;
    for (int i = 1; i < n; i++) {
        cout << parent[i] << " - " << i << "\t" << key[i] << endl;
    }
}

int find(int u, vector<int> &parent) {
    if (parent[u] == u) {
        return u;
    }
    parent[u] = find(parent[u], parent); // Path compression
    return parent[u];
}

void union_sets(int u, int v, vector<int> &parent, vector<int> &rank) {
    int root_u = find(u, parent);
    int root_v = find(v, parent);

    if (root_u != root_v) {
        // Union by rank
        if (rank[root_u] > rank[root_v]) {
            parent[root_v] = root_u;
        } else if (rank[root_u] < rank[root_v]) {
            parent[root_u] = root_v;
        } else {
            parent[root_v] = root_u;
            rank[root_u]++;
        }
    }
}

//KRUSKAL'S ALGORITHM
void MST_Kruskal(unordered_map<int, vector<pair<int,int>>> &adj, int n) {
    // Create a list of edges from the adjacency list
    vector<tuple<int, int, int>> edges; // {weight, u, v}
    for (auto &entry : adj) {
        int u = entry.first;
        for (auto &nbr : entry.second) {
            int v = nbr.first;
            int wt = nbr.second;
            if (u < v) { // to avoid duplicate edges in undirected graph
                edges.push_back({wt, u, v});
            }
        }
    }

    // Sort edges based on weight
    sort(edges.begin(), edges.end());

    // Disjoint Set Union (DSU) for cycle detection
    vector<int> parent(n), rank(n, 0);
    for (int i = 0; i < n; i++) parent[i] = i;

    cout << "Edge \tWeight" << endl;
    for (auto &edge : edges) {
        int wt, u, v;
        tie(wt, u, v) = edge;

        if (find(u, parent) != find(v, parent)) { // If u and v are in different sets
            union_sets(u, v, parent, rank); // Union the sets
            cout << u << " - " << v << "\t" << wt << endl; // Print the edge in MST
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
        g.addEdge(u,v,weight);
    }

    cout<<"MST using Prim's algorithm"<<endl;
    MST_Prim(g.adj, 0, n);

    cout<<"MST using Kruskal's algorithm"<<endl;
    MST_Kruskal(g.adj, n);

    return 0;

}