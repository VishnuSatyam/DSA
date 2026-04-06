#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    int helper(string &s, int i, int n, long num, int sign) {
        // stop condition
        if (i >= n || !isdigit(s[i])) {
            return sign * num;
        }

        int digit = s[i] - '0';

        // overflow check
        if (num > (INT_MAX - digit) / 10) {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }

        // recursive call (move forward)
        return helper(s, i + 1, n, num * 10 + digit, sign);
    }

    int myAtoi(string s) {
        int i = 0;
        int n = s.length();
        int sign = 1;

        // 1. Skip spaces (still iterative → better this way)
        while (i < n && s[i] == ' ') {
            i++;
        }

        // 2. Handle sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            i++;
        }

        // 3. Start recursion instead of loop
        return helper(s, i, n, 0, sign);
    }
};