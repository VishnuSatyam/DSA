// fibonacci number 

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fib(int n , vector<int> &dp){
        if(n <= 1) return n;

        if(dp[n] != -1) return dp[n];

        return dp[n] = fib(n-1 , dp) + fib(n-2 , dp);
    }

    int fib(int n) {
        vector<int> dp(n+1 , -1);
        return fib(n, dp);
    }
};

// tc is O(n) , sc is O(n)for recursion stack space + O(n) for array 



// bottom up approach 

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fib(int n) {
        if(n <= 1) return n;

        vector<int> dp(n + 1);

        dp[0] = 0;
        dp[1] = 1;

        for(int i = 2; i <= n; i++){
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};  // tc and sc same as previous one 



// to reduce the space complexity 

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fib(int n) {
        if(n <= 1) return n;

        int prev2 = 0 , prev = 1;
        for(int i = 2; i <= n; i++){
            int curr = prev + prev2;
            prev2 = prev;
            prev = curr;
        }

        return prev;
    }
}; // sc now become O(1);