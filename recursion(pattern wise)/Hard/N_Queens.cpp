class Solution {
public:

    bool isSafe(int row, int col, vector<string> board, int n) {

        // check upper diagonal
        int duprow = row;
        int dupcol = col;

        while(row >= 0 && col >= 0) {
            if(board[row][col] == 'Q') return false;
            row--;
            col--;
        }

        // check left side
        row = duprow;
        col = dupcol;

        while(col >= 0) {
            if(board[row][col] == 'Q') return false;
            col--;
        }

        // check lower diagonal
        row = duprow;
        col = dupcol;

        while(row < n && col >= 0) {
            if(board[row][col] == 'Q') return false;
            row++;
            col--;
        }

        return true;
    }

public:

    void solve(int col,
               vector<string> &board,
               vector<vector<string>> &ans,
               int n) {

        if(col == n) {
            ans.push_back(board);
            return;
        }

        for(int row = 0; row < n; row++) {

            if(isSafe(row, col, board, n)) {

                board[row][col] = 'Q';

                solve(col + 1, board, ans, n);

                // backtrack
                board[row][col] = '.';
            }
        }
    }

public:

    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> ans;

        vector<string> board(n);

        string s(n, '.');

        for(int i = 0; i < n; i++) {
            board[i] = s;
        }

        solve(0, board, ans, n);

        return ans;
    }
};



// optimized solution using hashing


class Solution {
public:

    void solve(int col, vector<string> &board, vector<vector<string>> &ans, vector<int> &leftRow, vector<int> &upperDiagonal, vector<int> &lowerDiagonal, int n) {

        // base case
        if(col == n) {
            ans.push_back(board);
            return;
        }

        // try placing queen in every row
        for(int row = 0; row < n; row++) {

            // check if safe
            if(leftRow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0) {

                // place queen
                board[row][col] = 'Q';

                leftRow[row] = 1;

                lowerDiagonal[row + col] = 1;

                upperDiagonal[n - 1 + col - row] = 1;

                // recursive call
                solve(col + 1,  board, ans,  leftRow,  upperDiagonal,  lowerDiagonal, n);

                // backtracking
                board[row][col] = '.';

                leftRow[row] = 0;

                lowerDiagonal[row + col] = 0;

                upperDiagonal[n - 1 + col - row] = 0;
            }
        }
    }

public:

    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> ans;

        vector<string> board(n);

        string s(n, '.');

        for(int i = 0; i < n; i++) {
            board[i] = s;
        }

        // hashing arrays

        vector<int> leftRow(n, 0);

        vector<int> upperDiagonal(2 * n - 1, 0);

        vector<int> lowerDiagonal(2 * n - 1, 0);

        solve(0,  board,  ans,  leftRow,  upperDiagonal,  lowerDiagonal,  n);

        return ans;
    }
};