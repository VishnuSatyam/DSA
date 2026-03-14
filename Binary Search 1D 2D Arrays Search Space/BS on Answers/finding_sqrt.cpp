// brute force 
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 28;
    int ans = 1;

    for (int i = 1; i <= n; i++) {
        if (i * i <= n) {
            ans = i;
        } else {
            break;
        }
    }

    cout << ans << endl;  // output: 5
    return 0;
}

// optimal approach using binary search 
int sqrt(int n) {
    if (n == 0 || n == 1) return n;

    int low = 1, high = n;
    long long ans = 0;

    while (low <= high) {
        long long mid = low + (high - low) / 2;

        if (mid * mid <= n) {
            ans = mid;        // possible answer
            low = mid + 1;    // try bigger
        } else {
            high = mid - 1;   // go left
        }
    }
    return ans;
}
