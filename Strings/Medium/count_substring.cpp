// approach 1 
#include<bits/stdc++.h>
using namespace std;
int countSubstring(string s){
    int n = s.length();
    int count = 0;

    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){  // 🔥 change here
            count++;
        }
    }
    return count;
}

// approach 2 

long long countSubstring(string s){
    long long n = s.length();
    return n * (n + 1) / 2;
}