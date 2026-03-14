// brute force aproach 
#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int> nums, int n) {
    vector<int> ans;

    for (int i = 0; i < n; i++) {
        int count = 0;

        // Count occurrences of nums[i]
        for (int j = 0; j < n; j++) {
            if (nums[j] == nums[i]) {
                count++;
            }
        }

        // If majority (> n/3) and not already included
        if (count > n/3 && find(ans.begin(), ans.end(), nums[i]) == ans.end()) {
            ans.push_back(nums[i]);
        }
    }

    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    vector<int> res = majorityElement(nums, n);

    for (int x : res) cout << x << " ";
}


// better  approach 

#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int>& arr) {
    int n = arr.size();
    unordered_map<int, int> mpp;
    vector<int> ls;
    
    int mn = n/3;  // threshold
    
    for (int i = 0; i < n; i++) {
        mpp[arr[i]]++;

        // If count crosses threshold and not already in result
        if (mpp[arr[i]] > mn) {
            if (find(ls.begin(), ls.end(), arr[i]) == ls.end()) {
                ls.push_back(arr[i]);
            }
        }
    }
    
    return ls;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<int> ans = majorityElement(arr);

    for (int x : ans) cout << x << " ";
}
