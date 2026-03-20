// brute force approach 

#include<bitset>/stdc++.h>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        int m = s.size();
        int n = goal.size();
        // edge case length must match 
        if(m!=n) return false;

        for(int i = 0;i<m;i++){
            rotate(s.begin() , s.begin()+1 , s.end() );

            if(s==goal){
                return true;
            }
        }
        return false;
    }
};


// optimal approach 


class Solution {
public:
    bool rotateString(string s, string goal) {
        int m = s.length();
        int n = goal.length();
        if(m!=n)  return false;
        if((s+s).find(goal) != string::npos){
            return true;
        }
        return false;
    }
};