// brute force approach 
#include <bits/stdc++.h>
using namespace std;

int minEatingSpeed(vector<int>& piles, int h) {
    int maxPile = *max_element(piles.begin(), piles.end());

    // try every possible speed
    for (int k = 1; k <= maxPile; k++) {
        long long hours = 0;

        for (int bananas : piles) {
            hours += (bananas + k - 1) / k; // ceil division // this is same like doing hours = ceil(bananas / k) 

        }

        if (hours <= h) {
            return k; // first valid speed is the answer
        }
    }
    return maxPile;
}

int main() {
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;

    cout << minEatingSpeed(piles, h);
    return 0;
}

// optimal approach using binary search 

#include <bits/stdc++.h>
using namespace std;

long long hoursNeeded(vector<int>& piles, int k) {
    long long hours = 0;
    for (int bananas : piles) {
        hours += (bananas + k - 1) / k;
    }
    return hours;
}

int minEatingSpeed(vector<int>& piles, int h) {
    int low = 1;
    int high = *max_element(piles.begin(), piles.end());
    int ans = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        long long hours = hoursNeeded(piles, mid);

        if (hours <= h) {
            ans = mid;        // mid is valid
            high = mid - 1;   // try smaller speed
        } else {
            low = mid + 1;    // need to eat faster
        }
    }
    return ans;
}

int main() {
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;

    cout << minEatingSpeed(piles, h);
    return 0;
}
