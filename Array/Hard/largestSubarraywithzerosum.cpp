#include<bits/stdc++.h>
using namespace std;
int maxLen(int A[], int n) {
    unordered_map<int, int> mpp;
    int sum = 0, maxi = 0;

    for (int i = 0; i < n; i++) {
        sum += A[i];

        // Case 1: subarray from 0 to i
        if (sum == 0) {
            maxi = i + 1;
        }

        // Case 2: prefix sum seen before
        else if (mpp.find(sum) != mpp.end()) {
            maxi = max(maxi, i - mpp[sum]);
        }

        // Store first occurrence only
        else {
            mpp[sum] = i;
        }
    }

    return maxi;
}
