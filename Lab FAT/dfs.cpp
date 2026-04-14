#include <bits/stdc++.h>
using namespace std; 

struct Graph {
    vector<vector<int>> adjList; 
    Graph(int V) {
        adjList.resize(V);
    } 
    void addEdge(int u, int v) {
        adjList[u].push_back(v); 
        adjList[v].push_back(u); 
    }
    void dfs(int start, vector<bool>& vis) {
        vis[start] = true;  
        cout << start << " "; 
        for (int i = 0; i < adjList[start].size(); i++) {
            if (!vis[adjList[start][i]]) {
                dfs(adjList[start][i], vis); 
            }
        }
    }
};

int main(void) {
    Graph g(5); 
    g.addEdge(1, 2);
    g.addEdge(1, 0); 
    g.addEdge(0, 2); 
    g.addEdge(2, 3); 
    g.addEdge(2, 4); 
    vector<bool> vis(5, 0); 
    g.dfs(0, vis);
    cout << endl; 
    return 0;
}