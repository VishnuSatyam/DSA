// brute force approach 

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";

        string ans = "";

        for(int i = 0; i < strs[0].size(); i++) {
            char ch = strs[0][i];

            for(int j = 1; j < strs.size(); j++) {
                // check bounds + mismatch
                if(i >= strs[j].size() || strs[j][i] != ch) {
                    return ans;
                }
            }

            ans += ch;
        }

        return ans;
    }
};

// optimal approach 


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";

        // Step 1: Sort the array
        sort(strs.begin(), strs.end());

        // Step 2: Take first and last string
        string first = strs[0];
        string last = strs[strs.size() - 1];

        string result = "";

        // Step 3: Compare characters
        for(int i = 0; i < first.length(); i++) {
            if(i >= last.length() || first[i] != last[i]) {
                break;
            }
            result += first[i];
        }

        return result;
    }
};