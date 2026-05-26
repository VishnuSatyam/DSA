#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isSafe(int node, int color[], bool graph[101][101], int n, int col) {

        for(int k = 0; k < n; k++) {

            if(k != node && graph[k][node] == 1 && color[k] == col) {
                return false;
            }
        }

        return true;
    }

    bool solve(int node, int color[], int m, int N, bool graph[101][101]) {

        // all nodes colored
        if(node == N) {
            return true;
        }

        // try all colors
        for(int i = 1; i <= m; i++) {

            if(isSafe(node, color, graph, N, i)) {

                color[node] = i;

                if(solve(node + 1, color, m, N, graph)) {
                    return true;
                }

                // backtrack
                color[node] = 0;
            }
        }

        return false;
    }

    bool graphColoring(bool graph[101][101], int m, int N) {

        int color[101] = {0};

        return solve(0, color, m, N, graph);
    }
};

int main() {

    Solution obj;

    int N = 4;
    int m = 3;

    bool graph[101][101] = {0};

    // edges
    graph[0][1] = 1;
    graph[1][0] = 1;

    graph[0][2] = 1;
    graph[2][0] = 1;

    graph[1][2] = 1;
    graph[2][1] = 1;

    graph[1][3] = 1;
    graph[3][1] = 1;

    if(obj.graphColoring(graph, m, N)) {
        cout << "Coloring possible";
    }
    else {
        cout << "Coloring not possible";
    }

    return 0;
}