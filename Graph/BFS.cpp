/*Push starting node
       ↓
Take front
       ↓
Visit its neighbours
       ↓
Push unvisited neighbours
       ↓
Repeat*/


void bfs(int start, vector<vector<int>>& adj, int n) {
    vector<int> vis(n, 0);
    queue<int> q;

    q.push(start);
    vis[start] = 1;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for (int neighbor : adj[node]) {
            if (!vis[neighbor]) {
                vis[neighbor] = 1;
                q.push(neighbor);
            }
        }
    }
}

/*Time: O(v) + O(2E)
Space: O(V)*/
