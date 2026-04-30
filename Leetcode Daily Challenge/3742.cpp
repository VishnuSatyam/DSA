class Solution {
public:
    int solve(vector<vector<int>> &grid, int k, int i, int j, int cost,
              vector<vector<vector<int>>> &memo, int m, int n) {

        if (i >= m || j >= n) return INT_MIN;

        int newCost = cost + (grid[i][j] > 0);

        if (newCost > k) return INT_MIN;

        if (i == m - 1 && j == n - 1) {
            return grid[i][j];
        }

        if (memo[i][j][newCost] != -1) {
            return memo[i][j][newCost];
        }

        int down = solve(grid, k, i + 1, j, newCost, memo, m, n);
        int right = solve(grid, k, i, j + 1, newCost, memo, m, n);

        int bestnext = max(down, right);

        if (bestnext == INT_MIN) {
            return memo[i][j][newCost] = INT_MIN;
        }

        return memo[i][j][newCost] = grid[i][j] + bestnext;
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> memo(
            m, vector<vector<int>>(n, vector<int>(k + 1, -1))
        );

        int result = solve(grid, k, 0, 0, 0, memo, m, n);

        return result == INT_MIN ? -1 : result;
    }
};