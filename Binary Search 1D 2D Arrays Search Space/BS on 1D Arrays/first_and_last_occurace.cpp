// brute force approach 
#include <bits/stdc++.h>
using namespace std;

vector<int> occurance(vector<int>& nums, int n, int target) {
    int first = -1, last = -1;

    for (int i = 0; i < n; i++) {
        if (nums[i] == target) {
            if (first == -1)
                first = i;
            last = i;
        }
    }

    return {first, last};
}

// better approach 

int lowerBound(vector<int>& arr, int n, int target) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= target) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}
int upperBound(vector<int>& arr, int x, int n){
    int low = 0, high = n - 1;
    int ans = n;
    while(low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if(arr[mid] > x) {
            ans = mid;
            // look for more small index on left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look for right
        }
    }
    return ans;
}
pair<int , int> firstandlastoccurance(vector<int>& nums, int n, int target){
    int lb = lowerBound(nums , n , target);
    if(lb==n || nums[lb]!=target) return {-1 , -1};
    return{lb , upperBound(nums , target , n)-1};

}


// using plain binary search without lower and upper bound 

#include <bits/stdc++.h>
int firstOccurrence(vector<int> &arr, int n, int k) {
    int low = 0, high = n - 1;
    int first = -1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(arr[mid] == k) {
            first = mid;
            high = mid - 1;
        }
        else if(arr[mid] < k) low = mid + 1;
        else high = mid - 1;
    }
    return first;
}

int lastOccurrence(vector<int> &arr, int n, int k) {
    int low = 0, high = n - 1;
    int last = -1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(arr[mid] == k) {
            last = mid;
            low = mid + 1;
        }
        else if(arr[mid] < k) low = mid + 1;
        else high = mid - 1;
    }
    return last;
}
pair<int , int> firstandlastoccurance(vector<int>&nums , int n , int k){
    int first = firstOccurrence(nums , n , k);
    if(first==-1) return {-1, -1};// if we did'nt got first then no sense to find the last 
    int last = lastOccurrence(nums , n ,k);
    return {first , last};
}