#include<bits/stdc++.h>
using namespace std;
int kthmissing(vector<int>&nums , int k){
    for(int i=0;i<nums.size();i++){
        if(nums[i]<=k)  k++;
        else{
            break;
        }
    }
    return k;
}

// optimal approach  use of binary search 



int missingK(vector<int> vec, int n, int k) {
    int low = 0, high = n - 1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        int missing = vec[mid] - (mid + 1);
        if(missing < k) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return k + high + 1;
}