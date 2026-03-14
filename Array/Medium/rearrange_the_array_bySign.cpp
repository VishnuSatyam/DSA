#include <bits/stdc++.h>
using namespace std;

vector<int> rearrangeArray(vector<int>& nums) {
    vector<int> pos, neg;

    // First pass → separate by sign
    for (int x : nums) {
        if (x >= 0) pos.push_back(x);
        else neg.push_back(x);
    }

    // Second pass → merge alternately
    vector<int> ans;
    int i = 0, j = 0;
    while (i < pos.size() && j < neg.size()) {
        ans.push_back(pos[i++]);
        ans.push_back(neg[j++]);
    }

    while (i < pos.size()) ans.push_back(pos[i++]);
    while (j < neg.size()) ans.push_back(neg[j++]);

    return ans;  
}

int main() {
    vector<int> nums = {3, 1, -2, -5, 2, -4};
    vector<int> result = rearrangeArray(nums);

    for (int x : result) cout << x << " ";
}


// optimal approach 


class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n= nums.size();
        vector<int> ans(n , 0);
        int posIndex=0 , negIndex=1;
        for(int i=0;i<n;i++){
            if(nums[i]<0){
                ans[negIndex] = nums[i];
                negIndex+=2;
            }
            else{
                ans[posIndex] = nums[i];
                posIndex+=2;
            }
        }
        return ans;
    }
};
