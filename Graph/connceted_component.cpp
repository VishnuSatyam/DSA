#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<int>& vis) {
    vis[node] = 1;

    for(auto neighbor : adj[node]) {
        if(!vis[neighbor]) {
            dfs(neighbor, adj, vis);
        }
    }
}

int main() {
    int n = 6;
    vector<vector<int>> adj(n);

    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[0].push_back(2);
    adj[2].push_back(0);

    adj[1].push_back(3);
    adj[3].push_back(1);

    adj[4].push_back(5);
    adj[5].push_back(4);

    vector<int> vis(n, 0);

    int count = 0;

    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            count++;
            dfs(i, adj, vis);
        }
    }

    cout << "Connected Components = " << count;

    return 0;
}