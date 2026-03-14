// brute force 
#include <bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        if ((i == 0 || arr[i] > arr[i - 1]) &&
            (i == n - 1 || arr[i] > arr[i + 1])) {
            return i;
        }
    }
    return -1;
}


// optimal approach using binary search 

class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int n = arr.size();

        if (n == 1) return 0;
        if (arr[0] > arr[1]) return 0;
        if (arr[n - 1] > arr[n - 2]) return n - 1;

        int low = 1, high = n - 2;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // peak found
            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
                return mid;
            }
            // both left and right increasing OR slope going up
            else if (arr[mid] > arr[mid - 1]) {
                low = mid + 1;
            }
            // slope going down
            else {
                high = mid - 1;  //  this will help cover the case when multiple peaks as well.
            }
        }

        return -1; // safety (theoretically unreachable)
    }
};
