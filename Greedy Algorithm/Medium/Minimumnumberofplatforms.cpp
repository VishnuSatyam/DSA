class Solution {
public:
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        int n = arr.size();
        int maxCnt = 0;

        for (int i = 0; i < n; i++) {
            int cnt = 1;

            for (int j = 0; j < n; j++) {
                if (i != j && arr[j] <= arr[i] && dep[j] >= arr[i]) {
                    cnt++;
                }
            }

            maxCnt = max(maxCnt, cnt);
        }

        return maxCnt;
    }
};

/*For every train i, check how many other trains are present when train i arrives.
Count trains j such that:
arr[j] <= arr[i]
dep[j] >= arr[i]

That means train j has already arrived but has not left yet when train i arrives.
Time: O(n²)
Space: O(1)*/



// better approach nlogn but sc O(n)
class Solution {
public:
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        int n = arr.size();
        vector<pair<int, char>> events;

        for (int i = 0; i < n; i++) {
            events.push_back({arr[i], 'A'});
            events.push_back({dep[i], 'D'});
        }

        sort(events.begin(), events.end(), [](auto &a, auto &b) {
            if (a.first == b.first)
                return a.second == 'A';
            return a.first < b.first;
        });

        int cnt = 0, maxCnt = 0;

        for (auto &event : events) {
            if (event.second == 'A') {
                cnt++;
                maxCnt = max(maxCnt, cnt);
            } else {
                cnt--;
            }
        }

        return maxCnt;
    }
};

// optimal approach using greedy 
/*Greedy idea

We have two events:

arr[i] → train arrives
dep[i] → train leaves

If another train arrives before or at the time the current train leaves, we need another platform.

So:

Sort all arrival times.
Sort all departure times.
Use two pointers:
i for arrivals
j for departures
If arr[i] <= dep[j]:
A train arrives before the earliest current departure.
Need one more platform.
i++
Otherwise:
A train has departed.
One platform becomes free.
j++*/

class Solution {
public:
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        int n = arr.size();

        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());

        int i = 0, j = 0;
        int cnt = 0, maxCnt = 0;

        while (i < n) {
            if (arr[i] <= dep[j]) {
                cnt++;
                maxCnt = max(maxCnt, cnt);
                i++;
            }
            else {
                cnt--;
                j++;
            }
        }

        return maxCnt;
    }
};

// tc is O2(nlog n + n) sc is O(1)