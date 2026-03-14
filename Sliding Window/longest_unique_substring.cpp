// brute force approach 
#include <bits/stdc++.h>
using namespace std;

int longestUniqueSubstring(string s) {
    int n = s.size();
    int maxLen = 0;

    for (int i = 0; i < n; i++) {

        vector<int> hash(256, 0);

        for (int j = i; j < n; j++) {

            if (hash[s[j]] == 1) {
                break;
            }

            hash[s[j]] = 1;

            int len = j - i + 1;
            maxLen = max(maxLen, len);
        }
    }

    return maxLen;
}

int main() {
    string s = "cadbzabcd";
    cout << longestUniqueSubstring(s);
}


//optimal approach using sliding window 


#include <bits/stdc++.h>
using namespace std;

int longestUniqueSubstring(string s) {

    vector<int> hash(256, -1);

    int l = 0, r = 0;
    int n = s.size();
    int maxLen = 0;

    while (r < n) {

        if (hash[s[r]] != -1) {

            if (hash[s[r]] >= l) {
                l = hash[s[r]] + 1;
            }
        }

        int len = r - l + 1;
        maxLen = max(maxLen, len);

        hash[s[r]] = r;

        r++;
    }

    return maxLen;
}

int main() {
    string s = "cadbzabcd";
    cout << longestUniqueSubstring(s);
}