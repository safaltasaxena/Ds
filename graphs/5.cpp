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

pair <int, vector<pair<int,int>> > Dijkstra(unordered_map<int, vector<pair<int,int>>> &adj, int start, int end,int n) {
    vector <int> distance(n, INT_MAX); // to store shortest distances
    vector <pair<int,int>> parent(n, {-1, -1}); // to reconstruct path
    distance[start] = 0; // distance to start node is 0
    parent[start] = {start, 0}; // parent of start node is itself

    set<pair<int,int>> s; // set to store (distance, node) pairs for efficient retrieval of minimum distance node
    s.insert({0, start}); // insert starting node with distance 0

    while(!s.empty()) {
        auto it = s.begin(); // get the node with the smallest distance
        int node = it->second;
        s.erase(it); // remove it from the set

        if (node == end) { // if we reached the end node, we can stop
            break;
        }

        for (auto neighbour : adj[node]) {
            int v = neighbour.first;
            int weight = neighbour.second;
            if (distance[node] + weight < distance[v]) {//this cnd works as visited no visisted bcz multiple nicer ways to reach same node we cant block it early as it may lead to a shorter path later on
                // If we found a shorter path to v
                if (distance[v] != INT_MAX) {
                    s.erase({distance[v], v}); // remove the old distance entry for v
                }
                distance[v] = distance[node] + weight; // update distance to v
                parent[v] = {node, weight}; // set parent for path reconstruction
                s.insert({distance[v], v}); // insert the new distance entry for v
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
    auto result = Dijkstra(g.adj,start, end,n);

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