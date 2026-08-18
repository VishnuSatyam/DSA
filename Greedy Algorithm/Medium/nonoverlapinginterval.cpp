class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& arr) {
        
        int n = arr.size();

        if (n == 0) {
            return 0;
        }

        // Sort intervals according to their ending time
        sort(arr.begin(), arr.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });

        // Keep the first interval
        int cnt = 1;
        int lastEndTime = arr[0][1];

        // Check the remaining intervals
        for (int i = 1; i < n; i++) {
            
            // Current interval does not overlap
            if (arr[i][0] >= lastEndTime) {
                cnt++;
                lastEndTime = arr[i][1];
            }
        }

        // Total intervals - intervals we kept
        return n - cnt;
    }
};

// tc is O(n log n) + O(n) = O(n log n)
// sc is O(1)