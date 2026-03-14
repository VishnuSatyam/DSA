// brute force approach using linear scan 

#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int>& arr) {
    int mini = arr[0];

    for(int i = 1; i < arr.size(); i++) {
        mini = min(mini, arr[i]);
    }
    return mini;
}

// optimal apparoach using binary search  

int findMin(vector<int>& nums) {
    int low = 0, high = nums.size() - 1;
    int ans = INT_MAX;

    while (low <= high) {

        // already sorted
        if (nums[low] <= nums[high]) {
            ans = min(ans, nums[low]);
            break;
        }

        int mid = low + (high - low) / 2;

        if (nums[low] <= nums[mid]) {
            ans = min(ans, nums[low]);
            low = mid + 1;
        } else {
            ans = min(ans, nums[mid]);
            high = mid - 1;
        }
    }
    return ans;
}

// If array having duplicates 

int findMin(vector<int>& nums) {
    int low = 0, high = nums.size() - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] < nums[high]) {
            // minimum is in left part including mid
            high = mid;
        }
        else if (nums[mid] > nums[high]) {
            // minimum is in right part
            low = mid + 1;
        }
        else {
            // nums[mid] == nums[high] → can't decide
            high--;
        }
    }
    return nums[low];
}