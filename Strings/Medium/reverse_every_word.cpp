class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string ans = "";
        reverse(s.begin(),s.end());

        for(int i=0;i<n;i++){
            string word = "";
            // for udentiifying single word
            while(i<n && s[i]!=' '){
                word+= s[i];
                i++;
            }

            reverse(word.begin(), word.end());
            if(word.length()>0){
                ans+= " " + word;
            }
        }

        return ans.substr(1);
    }
};

// tc is O(n2)
// sc is O(1)