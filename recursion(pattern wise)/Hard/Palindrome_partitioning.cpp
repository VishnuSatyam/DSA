class Solution {
public:
        bool isPalindrome(string s){
            string s2 = s;
            reverse(s2.begin() , s2.end());
            return s = s2;
        }
    void getAllParts(string s , vector<string> & partition , vector<vector<string>> &ans){

        if(s.size()==0){
            ans.push_back(partition);
            return;
        }

        for(int i =0;i<s.size();i++){
            string part = s.substr(0 , i+1);
            if(isPalindrome(part)){
                partition.push_back(part);
                getAllParts(s.substr(i+1) , partition , ans);
                partition.pop_back(); // backtracking
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> partition;

        getAllParts(s , partition , ans);
        return ans;
    }
};