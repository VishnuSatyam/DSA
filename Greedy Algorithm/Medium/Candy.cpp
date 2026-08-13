class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> left(n,1);
        vector<int>right(n,1);
        for(int i = 1; i<n; i++){
            if(ratings[i]>ratings[i-1]){
                left[i] = left[i - 1] + 1;
            }
        }
         for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                right[i] = right[i + 1] + 1;
            }
        }

        int ans = 0;
        for(int i =0; i<n; i++){
            ans += max(left[i], right[i]);
        }
        return ans;

    }
};

// tc is O(n) and sc is O(n)  

// optimal approach using the slope intution


class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int candies = n;
        int i = 1;

        while (i < n) {
            if (ratings[i] == ratings[i - 1]) {
                i++;
                continue;
            }

            int peak = 0;

            while (i < n && ratings[i] > ratings[i - 1]) {
                peak++;
                candies += peak;
                i++;
            }

            int valley = 0;

            while (i < n && ratings[i] < ratings[i - 1]) {
                valley++;
                candies += valley;
                i++;
            }

            candies -= min(peak, valley);
        }

        return candies;
    }
};