//Floor (greatest ≤ target

#include<bits/stdc++.h>
using namespace std;
int findFloor(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;
    int ans = -1;   // stores index of floor

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] <= target) {
            ans = mid;        // possible floor
            low = mid + 1;    // try to find bigger one
        } else {
            high = mid - 1;
        }
    }
    return ans; // -1 if no floor exists
}



//Ceil (smallest ≥ target)



int findCeil(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;
    int ans = nums.size();  // stores index of ceil

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] >= target) {
            ans = mid;        // possible ceil
            high = mid - 1;   // try to find smaller one
        } else {
            low = mid + 1;
        }
    }
    return ans; // n if no ceil exists
}




/*
Relation to STL :

ceil  = *lower_bound(nums.begin(), nums.end(), target);
floor = *(lower_bound(nums.begin(), nums.end(), target) - 1);

*/