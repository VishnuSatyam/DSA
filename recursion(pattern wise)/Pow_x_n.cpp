#include<bits/stdc++.h>
using namespace std;

// brute force approach 
class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;

        long long N = n;  // handle negative safely

        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        for (long long i = 0; i < N; i++) {
            ans = ans * x;
        }

        return ans;
    }
};

// optimal approach : Binary exponentiation

class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;

        long long N = n;

        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        while (N > 0) {
            if (N % 2 == 0) {
                x = x * x;
                N = N / 2;
            } else {
                ans = ans * x;
                N = N - 1;
            }
        }

        return ans;
    }
};