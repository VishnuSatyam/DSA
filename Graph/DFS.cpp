#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<int>& vis) {
    vis[node] = 1;

    cout << node << " ";

    for(auto neighbor : adj[node]) {
        if(!vis[neighbor]) {
            dfs(neighbor, adj, vis);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    vector<int> vis(n, 0);

    // Undirected graph
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // DFS for all components
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            dfs(i, adj, vis);
        }
    }

    return 0;
}


// sc will be O(N) for storing nodes in dfs traversal  + O(N) for visited + O(N) for stack space = O(N)

// tc will be O(N) for calling the function once  + O(2E)for visiting all the neighbours for undirected graph for directed it will become just no. of edges that is E