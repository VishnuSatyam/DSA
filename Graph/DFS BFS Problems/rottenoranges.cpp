class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int, int>, int>>q;

        int vis[n][m];
        for(int i =0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] ==2){
                    q.push({{i, j}, 0});
                    vis[i][j] =2;
                }
                else{
                    vis[i][j]=0;
                }
            }
        }

        int tm =0;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            tm = max(tm, t);
            q.pop();

            for(int i=0; i<4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol <m && vis[nrow][ncol]!= 2 && grid[nrow][ncol]==1){
                    q.push({{nrow, ncol}, t+1});
                    vis[nrow][ncol]=2;
                }
            }
        }
        for(int i =0; i<n; i++){
            for(int j =0; j<m; j++){
                if(vis[i][j]!=2 && grid[i][j]==1) return -1;
            }
        }
        return tm;
    }
};

/*
INTUITION:
- This is Multi-Source BFS because rotting starts simultaneously from ALL rotten oranges.
- Put every rotten orange in the queue initially with time = 0.
- BFS spreads rot to adjacent fresh oranges; when an orange rots at time t,
  its fresh neighbour rots at t + 1.
- Store time with each cell to know how long it took to reach that orange.
- The maximum time reached = total minutes needed.
- Mark visited oranges so the same orange isn't added multiple times.
- After BFS, if any fresh orange is still left -> it was unreachable -> return -1.

PATTERN:
Multiple starting points + minimum time to reach all cells = Multi-Source BFS
*/



// tc is O(n*m) and sc is O(n*m) for the queue and visited array.