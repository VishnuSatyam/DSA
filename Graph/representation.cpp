// matrix storage representation of a graph

#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int adj[n+1][n+1];

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    return 0;
}
// sc is O(N*N)

// for optimal storage we use adjacency list representation of a graph

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> adj[n+1];

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    return 0;
}
// space is O(2Edges)

// if graph is directed then we will not add the edge in reverse direction
// in this case space will be O(Edges )



/*if graph is weighted then in matrix way instead of storing 1 we store weight of that edge.


In case of list storage for weighted graph,
   instead of storing only the neighboring vertex,
   we store a pair of {neighbor, weight}.

*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> adj[n+1];

    for(int i = 0; i < m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    return 0;
}
