#include<bits/stdc++.h>
using namespace std;
int search(vector<int>&nums , int target ){
    int n=nums.size();
    int low=0 ,   high = n-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(nums[mid]==target) return mid;
        else if(nums[mid]<target) low=mid+1;
        else high = mid-1;
    }
    return -1;
}


// recursive approach 

#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>& nums, int low, int high, int target) {
    if (low > high) return -1;   // base case

    int mid = low + (high - low) / 2;

    if (nums[mid] == target)
        return mid;
    else if (nums[mid] < target)
        return binarySearch(nums, mid + 1, high, target);
    else
        return binarySearch(nums, low, mid - 1, target);
}

// wrapper function (clean API)
int search(vector<int>& nums, int target) {
    return binarySearch(nums, 0, nums.size() - 1, target);
}