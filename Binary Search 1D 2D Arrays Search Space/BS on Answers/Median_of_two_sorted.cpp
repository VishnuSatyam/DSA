// naive brute force approach 

#include<bits/stdc++.h>
using namespace std;
double median (vector<int>& arr1 , vector<int>& arr2){
    int n = arr1.size();
    int m = arr2.size();
    vector<int>ans;
    int i = 0 , j = 0;
    while(i<n && j<m){
        if(arr1[i]<=arr2[j]){
            ans.push_back(arr1[i]);
            i++;
        }
        else{
            ans.push_back(arr2[j]);
            j++;
        }
    }
    while(i<n){
        ans.push_back(arr1[i]);
        i++;
    }
    while(j<m){
        ans.push_back(arr2[j]);
        j++;
    }
    int size = ans.size();
    if(size%2==0){
        return (ans[size/2] + ans[size/2-1])/2.0;
    }
    else{
        return ans[size/2];
    }
}

// brute force approch 

#include<bits/stdc++.h>
using namespace std;

double median(vector<int>& arr1, vector<int>& arr2) {
    int n = arr1.size();
    int m = arr2.size();
    int total = n + m;

    int mid = total / 2;
    int i = 0, j = 0;
    int prev = -1, curr = -1;  // track last two elements at middle

    for (int count = 0; count <= mid; count++) {
        prev = curr;

        // Pick smaller element from either array (simulated merge)
        if (i < n && (j >= m || arr1[i] <= arr2[j])) {
            curr = arr1[i++];
        } else {
            curr = arr2[j++];
        }
    }

    if (total % 2 == 0)
        return (prev + curr) / 2.0;
    else
        return curr;
}

// optimal approach using binary search 

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        // always binary search on smaller array
        if(nums2.size() < nums1.size())
            return findMedianSortedArrays(nums2, nums1);

        int n1 = nums1.size();
        int n2 = nums2.size();

        int low = 0, high = n1;

        while(low <= high){

            int cut1 = (low + high) >> 1;  // this is equivalent to int cut1 = (low + high) / 2;
            int cut2 = (n1 + n2 + 1) / 2 - cut1;

            int left1  = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int left2  = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];

            int right1 = (cut1 == n1) ? INT_MAX : nums1[cut1];
            int right2 = (cut2 == n2) ? INT_MAX : nums2[cut2];

            if(left1 <= right2 && left2 <= right1){

                if((n1 + n2) % 2 == 0){
                    return (max(left1, left2) + min(right1, right2)) / 2.0;
                }
                else{
                    return max(left1, left2);
                }
            }
            else if(left1 > right2){
                high = cut1 - 1;
            }
            else{
                low = cut1 + 1;
            }
        }

        return 0.0;
    }
};