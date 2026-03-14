#include<bits/stdc++.h>
using namespace std;
int rotationCount(vector<int>& nums) {
    int low = 0, high = nums.size() - 1;

    while (low <= high) {

        // already sorted → minimum at low
        if (nums[low] <= nums[high]) {
            return low;
        }

        int mid = low + (high - low) / 2;
        int next = (mid + 1) % nums.size();
        int prev = (mid - 1 + nums.size()) % nums.size();

        // mid itself is minimum
        if (nums[mid] <= nums[next] && nums[mid] <= nums[prev]) {
            return mid;
        }

        // left part sorted → go right
        if (nums[low] <= nums[mid]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return 0;
}