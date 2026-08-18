//The key idea is:

//Always try to take the job with the highest profit first, and put it in the latest available slot before its deadline.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> JobScheduling(vector<vector<int>>& Jobs) {
        int n = Jobs.size();

        sort(Jobs.begin(), Jobs.end(), [](vector<int>& a, vector<int>& b) {
            return a[2] > b[2];
        });

        int maxDeadline = 0;
        for (auto& job : Jobs) {
            maxDeadline = max(maxDeadline, job[1]);
        }
 
        vector<int> slot(maxDeadline + 1, -1);

        int count = 0;
        int profit = 0;

        for (auto& job : Jobs) {
            int id = job[0];
            int deadline = job[1];
            int jobProfit = job[2];

            for (int j = deadline; j >= 1; j--) {
                if (slot[j] == -1) {
                    slot[j] = id;
                    count++;
                    profit += jobProfit;
                    break;
                }
            }
        }

        return {count, profit};
    }
};
/*The Time Complexity is \(O(N \log N + N \times M)\) and the Space Complexity is \(O(M)\), where \(N\) is the number of jobs and \(M\) is the maximum deadline among all jobs*/