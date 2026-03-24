// to check whether palindrome or not 

// iterative way 

i = 0;
j = n - 1;

while (i <= j) {
    if (s[i] == s[j]) {
        i++;
        j--;
    } else {
        return false;
    }
}
return true;


// recursive way 

bool solve(int i, int j, string &s) {
    if (i >= j) return true;

    if (s[i] == s[j]) {
        return solve(i + 1, j - 1, s);
    } else {
        return false;
    }
}


// longest palindrome substring problem


// without using memorization

class Solution {
public:
    bool isPalindrome(string &s, int i, int j) {
        if (i >= j) return true;

        if (s[i] == s[j])
            return isPalindrome(s, i + 1, j - 1);

        return false;
    }

    string longestPalindrome(string s) {
        int n = s.length();

        int maxLen = 0;
        int start = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {

                if (isPalindrome(s, i, j)) {
                    if (j - i + 1 > maxLen) {
                        maxLen = j - i + 1;
                        start = i;
                    }
                }

            }
        }

        return s.substr(start, maxLen);
    }
};




class Solution {
public:
    string expand(string &s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return s.substr(left + 1, right - left - 1);
    }

    string longestPalindrome(string s) {
        string ans = "";

        for (int i = 0; i < s.size(); i++) {
            string odd = expand(s, i, i);       // odd length
            string even = expand(s, i, i + 1);  // even length

            if (odd.length() > ans.length()) ans = odd;
            if (even.length() > ans.length()) ans = even;
        }

        return ans;
    }
};