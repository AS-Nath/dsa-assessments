#include <bits/stdc++.h>
using namespace std;

struct Graph {
    int v; 
    vector<vector<int>> adjList; 
    Graph(int V) : v{V} {
        adjList.resize(V); 
    }
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); 
    }
    void delEdge(int u, int v) {
        auto it = find(adjList[u].begin(), adjList[u].end(), v);
        adjList[u].erase(it); 
        it = find(adjList[v].begin(), adjList[v].end(), u);
        adjList[v].erase(it); 
    }
    void dfs(int start, vector<bool>& vis) {
        vis[start] = true; 
        cout << start << " "; 
        for (int i : adjList[start]) {
            if (!vis[i]) {
                dfs(i, vis); 
            }
        }
    }
};

int main(void) {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(0, 2); 
    g.addEdge(2, 3);
    g.addEdge(2, 4);
    vector<bool> vis(g.v, 0); 
    g.dfs(0, vis);
    cout << endl; 
    return 0; 
}