class Solution {
    void dfs(int row, int col, vector<vector<int>> & ans, vector<vector<int>>& image, int newcolor, int drow[], int dcol[], int inicolor){
        ans[row][col] = newcolor;
        int n = image.size();
        int m = image[0].size();

        for(int i =0; i<4; i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol] == inicolor && ans[nrow][ncol] != newcolor){
                dfs(nrow, ncol, ans, image, newcolor, drow, dcol, inicolor);
            }
        }
        
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int inicolor = image[sr][sc];
        vector<vector<int>> ans = image;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        dfs(sr, sc, ans, image, color, drow, dcol, inicolor);

        return ans;
    }
};

/*TC: O(N × M)
SC: O(N × M)*/

/*
INTUITION / REVISION:

1. Flood Fill:
   Start from (sr, sc) and change the color of all 4-directionally
   connected cells having the SAME ORIGINAL COLOR as the starting cell.

2. Why `inicolor`?
   We must remember the starting cell's original color.
   Only cells with `image[nrow][ncol] == inicolor` should be visited.

3. Why `ans`?
   `image` is kept unchanged as the original/reference image.
   `ans` is its copy and is modified to store the final answer.
   
   ans[row][col] = newcolor;   // actual change happens here

4. DFS:
   Color the current cell first, then explore its:
       UP, RIGHT, DOWN, LEFT
   If a neighbour is:
       - inside the grid
       - original color == inicolor
       - not already changed to newcolor
     then recursively flood-fill it.

5. Why `drow` and `dcol`?
   They represent the 4 possible movements:
       UP    = (-1, 0)
       RIGHT = (0, 1)
       DOWN  = (1, 0)
       LEFT  = (0, -1)

6. Why check `ans[nrow][ncol] != newcolor`?
   Once a cell is changed to `newcolor`, don't process it again.
   This prevents repeated visits / infinite recursion.

7. Important edge case:
   If `inicolor == newcolor`, nothing needs to change.
   Return the image directly.

8. Pattern to remember:
   COPY → remember ORIGINAL COLOR → DFS → COLOR current cell →
   explore 4 neighbours → only visit cells with ORIGINAL COLOR.

TC: O(N*M)
SC: O(N*M)  // ans + worst-case DFS recursion stack
*/