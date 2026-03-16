// brute force approach 

#include<bits/stdc++.h>
using namespace std;

int median (vector<vector<int>>& mat){
    int n = mat.size();
    int m = mat[0].size();
    vector<int> ans;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ans.push_back(mat[i][j]);
        }
    }
    sort(ans.begin() , ans.end());
    return ans[ans.size()/2]
    return -1;
}  



// optimal approach using binary search 

#include <bits/stdc++.h>
using namespace std;

int median(vector<vector<int>> &mat, int r, int c) {

    int low = mat[0][0];
    int high = mat[0][c-1];

    for(int i = 1; i < r; i++){
        low = min(low, mat[i][0]);
        high = max(high, mat[i][c-1]);
    }

    int desired = (r*c + 1) / 2;

    while(low < high){

        int mid = (low + high) / 2;
        int count = 0;

        for(int i = 0; i < r; i++){
            count += upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin(); // this will give number of elements ≤ mid 
        }

        if(count < desired)
            low = mid + 1;
        else
            high = mid;
    }

    return low;
}