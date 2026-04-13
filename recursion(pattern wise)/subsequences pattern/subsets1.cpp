#include <vector>
using namespace std;

class Solution {
public:
    void backtrack(vector<vector<int>>& result, vector<int>& temp, vector<int>& nums, int start) {
        
        // Base case
        if (start == nums.size()) {
            result.push_back(temp);
            return;
        }

        // 1️⃣ Take the element
        temp.push_back(nums[start]);
        backtrack(result, temp, nums, start + 1);

        // Backtrack
        temp.pop_back();

        // 2️⃣ Skip the element
        backtrack(result, temp, nums, start + 1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;

        backtrack(result, temp, nums, 0);
        return result;
    }
};