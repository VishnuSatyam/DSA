// brute force approach 
// tc is O(n*k) and sc is O(n)
#include <bits/stdc++.h>
using namespace std;

long double minimiseMaxDistance(vector<int>& arr, int k) {
    int n = arr.size();

    vector<int> howMany(n - 1, 0);

    for (int gasStations = 1; gasStations <= k; gasStations++) {

        long double maxSection = -1;
        int maxInd = -1;

        for (int i = 0; i < n - 1; i++) {

            long double diff = arr[i + 1] - arr[i];

            long double sectionLen = diff / (long double)(howMany[i] + 1);

            if (sectionLen > maxSection) {
                maxSection = sectionLen;
                maxInd = i;
            }
        }

        howMany[maxInd]++;
    }

    long double maxAns = -1;

    for (int i = 0; i < n - 1; i++) {

        long double diff = arr[i + 1] - arr[i];
        long double sectionLen = diff / (long double)(howMany[i] + 1);

        maxAns = max(maxAns, sectionLen);
    }

    return maxAns;
}



// better approach using priority queue
// tc is O(k log n) and sc is O(n)

#include <bits/stdc++.h>
using namespace std;

long double minimiseMaxDistance(vector<int>& arr, int k) {

    int n = arr.size();

    vector<int> howMany(n - 1, 0);

    priority_queue<pair<long double, int>> pq;

    for (int i = 0; i < n - 1; i++) {
        pq.push({arr[i + 1] - arr[i], i});
    }

    for (int gasStations = 1; gasStations <= k; gasStations++) {

        auto tp = pq.top();
        pq.pop();

        int secInd = tp.second;

        howMany[secInd]++;

        long double diff = arr[secInd + 1] - arr[secInd];

        long double newSection = diff / (long double)(howMany[secInd] + 1);

        pq.push({newSection, secInd});
    }

    return pq.top().first;
}

// optimal approach using binary search
// tc is O(n log (max - min)) and sc is O(1)

#include <bits/stdc++.h>
using namespace std;

int numberOfGasStationsRequired(long double dist, vector<int>& arr) {

    int n = arr.size();
    int cnt = 0;

    for (int i = 1; i < n; i++) {

        int numberInBetween = (arr[i] - arr[i - 1]) / dist;

        if ((arr[i] - arr[i - 1]) == numberInBetween * dist)
            numberInBetween--;

        cnt += numberInBetween;
    }

    return cnt;
}

long double minimiseMaxDistance(vector<int>& arr, int k) {

    int n = arr.size();

    long double low = 0;
    long double high = 0;

    for (int i = 0; i < n - 1; i++) {
        high = max(high, (long double)(arr[i + 1] - arr[i]));
    }

    long double diff = 1e-6;

    while (high - low > diff) {

        long double mid = (low + high) / 2.0;

        int cnt = numberOfGasStationsRequired(mid, arr);

        if (cnt > k)
            low = mid;
        else
            high = mid;
    }

    return high;
}