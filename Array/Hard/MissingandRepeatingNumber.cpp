// brute force approach 
#include <bits/stdc++.h>
using namespace std;

vector<int> Missing_and_repeating(vector<int> arr, int n) {
    int missing = -1, repeating = -1;

    for (int i = 1; i <= n; i++) {
        int count = 0;

        for (int j = 0; j < n; j++) {
            if (arr[j] == i) {
                count++;
            }
        }

        if (count == 0) {
            missing = i;
        }
        else if (count == 2) {
            repeating = i;
        }
    }

    return {repeating, missing};
}

// better approach 
vector<int>  Missing_and_repeating(vector<int>arr , int n){
    int n= arr.size();
    int hash[n+1]={0};
    for(int i=0;i<n;i++){
        hash[arr[i]]++;
    }
    int repeating =-1 , missing =-1;
    for(int i=1;i<=n;i++){
        if(hash[i]==2) repeating =i;
        else if(hash[i]==0) missing =0;

        if(repeating !=-1 && missing !=-1) break;
    }
    return {repeating , missing };
}

// optimal approach using maths 

vector<int> findMissingRepeatingNumbers(vector < int > a) {
    long long n = a.size();
    // S - Sn = x - y
    // S2 - S2N
    long long SN = (n * (n+1)) / 2;
    long long S2N = (n * (n+1) * (2*n+1)) / 6;
    long long S = 0, S2 = 0;
    for(int i = 0; i<n; i++) {
        S += a[i];
        S2 += (long long)a[i] * (long long)a[i];
    }
    long long val1 = S - SN; // x - y
    long long val2 = S2 - S2N;
    val2 = val2 / val1; // x + y
    long long x = (val2 + val1) / 2;
    long long y = x - val1;
    return {(int)x, (int)y};
}

// optimal approach using xor 
// do it after bit manipulation...