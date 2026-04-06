#include <bits/stdc++.h>
using namespace std;

void generate(int n, string current, bool prevOne) {
    if (current.length() == n) {
        cout << current << endl;
        return;
    }

    // Always place 0
    generate(n, current + '0', false);

    // Place 1 only if previous was not 1
    if (!prevOne) {
        generate(n, current + '1', true);
    }
}

int main() {
    int n;
    cin >> n;   // works for any n

    generate(n, "", false);
}


// to also return the count 


class Solution {
public:
    long long countStrings(int n) {
        long long MOD = 1000000007; // we are using mod coz ans will be very large so to avoid overflow
        long long zeroEnd = 1; // "0"
        long long oneEnd = 1;  // "1"

        for (int i = 2; i <= n; i++) {
            long long newZeroEnd = (zeroEnd + oneEnd) % MOD;
            long long newOneEnd = zeroEnd % MOD;

            zeroEnd = newZeroEnd;
            oneEnd = newOneEnd;
        }

        return (zeroEnd + oneEnd) % MOD;
    }
};