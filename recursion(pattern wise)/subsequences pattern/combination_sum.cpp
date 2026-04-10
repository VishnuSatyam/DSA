#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void getAllCombination(vector<int>& arr, int idx, int target, vector<vector<int>> &ans, vector<int> &combin) {
        
        // base case
        if (target == 0) {
            ans.push_back(combin);
            return;
        }

        if (idx == arr.size() || target < 0) {
            return;
        }

        // include (multiple allowed)
        combin.push_back(arr[idx]);
        getAllCombination(arr, idx, target - arr[idx], ans, combin);
        combin.pop_back();

        //skip duplicates in exclusion
        int next = idx + 1;
        while (next < arr.size() && arr[next] == arr[idx]) {
            next++;
        }

        // exclusion
        getAllCombination(arr, next, target, ans, combin);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combin;

        sort(candidates.begin(), candidates.end()); // to deal with duplicate like in ex [2 , 3, 3]

        getAllCombination(candidates, 0, target, ans, combin);

        return ans;
    }
};