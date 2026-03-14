#include<bits/stdc++.h>
using namespace std;
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
int coutnoccurances(vector<int>&nums , int n , int x){
    pair<int, int> ans = firstandlastoccurance(nums , n , x);
    if(ans.first==-1) return 0;
    return ans.second-ans.first+1; 
}