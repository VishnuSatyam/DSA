// brute force approach 

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // 🔴 Edge case
        if(s.size() != t.size()) return false;

        int n = s.size();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {

                // same in s → must be same in t
                if(s[i] == s[j] && t[i] != t[j]) {
                    return false;
                }

                // different in s → must be different in t
                if(s[i] != s[j] && t[i] == t[j]) {
                    return false;
                }
            }
        }

        return true;
    }
};


// optimal approach 

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // Edge case: lengths must match
        if (s.length() != t.length()) return false;

        unordered_map<char, char> mp1;
        unordered_map<char, char> mp2;

        int n = s.length();

        for (int i = 0; i < n; i++) {
            char ch1 = s[i];
            char ch2 = t[i];

            if ((mp1.find(ch1) != mp1.end() && mp1[ch1] != ch2) ||
                (mp2.find(ch2) != mp2.end() && mp2[ch2] != ch1)) {
                return false;
            }
            mp1[ch1] = ch2;
            mp2[ch2] = ch1;
        }

        return true;
    }
};