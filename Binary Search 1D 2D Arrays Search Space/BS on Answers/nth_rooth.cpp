#include <bits/stdc++.h>
using namespace std;

// helper function to calculate base^exp safely
long long power(long long base, int exp, long long limit) {
    long long result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;//   Instead of doing pow(base, exp):  We multiply one step at a time  This allows us to stop early
        if (result > limit) return limit + 1; // stop early to avoid overflow
    }
    return result;
}

// function to find integer nth root (floor value)
int nthRoot(int n, int m) {
    int low = 1, high = n;
    int ans = -1;

    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        long long val = power(mid, m, n);

        if (val == n) {
            return mid;          // exact nth root found
        } 
        else if (val < n) {
            ans = mid;           // possible answer
            low = mid + 1;       // try larger values
        } 
        else {
            high = mid - 1;      // reduce search space
        }
    }
    return ans;                  // floor nth root
}

int main() {
    int n, m;
    cout << "Enter n and m: ";
    cin >> n >> m;

    int result = nthRoot(n, m);
    cout << "Nth root = " << result << endl;

    return 0;
}




class Solution {
public:
    int countPrimes(int n) {
        int count= 0;
        for(int i=2;i<n;i++){
            bool isprime = true;
            for(int j=2;j*j<=i;j++){
                if(i%j==0){
                    isprime = false;
                }
                break;
            }
            if(isprime) count++;
        }
        return count;
    }
};