// 1. Sort children by greed.
// 2. Sort cookies by size.
// 3. Start with the least greedy child and the smallest cookie.
// 4. If the cookie can satisfy the child, assign it and move to the next child.
// 5. Regardless, move to the next cookie because the current one has been used
//    (or is too small and cannot satisfy any remaining child).
// 6. When either all children or all cookies are processed, the number of
//    satisfied children is the answer.

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int m = g.size();
        int n = s.size();
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int left = 0, right = 0; // left is the index for children, right is the index for cookies

        while(left<m && right<n){
            if(g[left] <= s[right]){
                left++;
            }
            right++;
        }

        return left;

    }
};

// tc and sc will be O(m log m + n log n) and O(1)