// brute force approach 
#include <bits/stdc++.h>
using namespace std;

int subarrayXor(vector<int>& nums, int target) {
    int n = nums.size();
    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int xr = 0;
            for (int k = i; k <= j; k++) {
                xr ^= nums[k];
            }
            if (xr == target) {
                count++;
            }
        }
    }
    return count;
}


// better approach 
#include <bits/stdc++.h>
using namespace std;

int subarray(vector<int>& nums, int target) {
    int n = nums.size();
    int count = 0;

    for (int i = 0; i < n; i++) {
        int XR = 0;
        for (int j = i; j < n; j++) {
            XR = XR ^ nums[j];
            if (XR == target) {
                count++;
            }
        }
    }
    return count;
}

//optimal approach 

int subarraysWithSumK(vector<int> a, int k) {
    int xr = 0;
    map<int,int> mpp;
    mpp[xr]++;          // it will make sure {0 : 1} iis inserted in map 
    int cnt = 0;

    for(int i = 0; i < a.size(); i++) {
        xr = xr ^ a[i];
        int x = xr ^ k;
        cnt += mpp[x];
        mpp[xr]++;
    }
    return cnt;
}
