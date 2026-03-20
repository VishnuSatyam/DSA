// brute force approach 

class Solution {
public:
    bool isAnagram(string s, string t) {
        int m = s.size();
        int n = t.size();
        if(m!=n) return false;
        sort(s.begin(), s.end());

        sort(t.begin(), t.end());

        if(s==t){
            return true;
        }
        return false;
    }
};


// optimal approach using freq count 

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;

        vector<int> freq(26, 0);

        for(char c : s) freq[c - 'a']++;
        for(char c : t) freq[c - 'a']--;

        for(int count : freq) {
            if(count != 0) return false;
        }
        return true;
    }
};