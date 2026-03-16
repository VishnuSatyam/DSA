// using stack 

#include <bits/stdc++.h>
using namespace std;

string removeOuterParentheses(string s) {
    stack<char> st;
    string ans = "";

    for(char c : s) {

        if(c == '(') {
            if(!st.empty()) {
                ans += c;
            }
            st.push(c);
        }

        else { // ')'
            st.pop();
            if(!st.empty()) {
                ans += c;
            }
        }
    }

    return ans;
}

// using count variable


class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int count = 0;

        for(char c : s) {

            if(c == '(') {
                if(count > 0)
                    ans += c;
                count++;
            }
            else {
                count--;
                if(count > 0)
                    ans += c;
            }
        }

        return ans;
    }
};