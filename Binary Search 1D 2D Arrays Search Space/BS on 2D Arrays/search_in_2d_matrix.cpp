// brute force for leetcode 74

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int rows = matrix.size();
        int cols = matrix[0].size();

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                
                if(matrix[i][j] == target) {
                    return true;
                }
                if(matrix[i][j]>target) break;

            }
        }

        return false;
    }
};

// optimal approach using binary search 

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int rows = matrix.size();
        int cols = matrix[0].size();

        int low = 0;
        int high = rows * cols - 1;

        while(low <= high){

            int mid = (low + high) / 2;

            int r = mid / cols;
            int c = mid % cols;

            if(matrix[r][c] == target)
                return true;

            else if(matrix[r][c] < target)
                low = mid + 1;

            else
                high = mid - 1;
        }

        return false;
    }
};


// for gfg problem   Search in a Row-Column Sorted

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        if(matrix.empty() || matrix[0].empty())
            return false;

        int n = matrix.size();
        int m = matrix[0].size();

        int i = 0;
        int j = m - 1;

        while(i < n && j >= 0){

            if(matrix[i][j] == target)
                return true;

            else if(matrix[i][j] > target)
                j--;

            else
                i++;
        }

        return false;
    }
};