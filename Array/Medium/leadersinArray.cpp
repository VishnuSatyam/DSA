#include<bits/stdc++.h>
using namespace std;
vector<int>ArrayLeader(vector<int> arr , int n){
    vector<int> ans;
    for(int i=0;i<n;i++){
        bool leader = true;
        for(int j=i+1;j<n;j++){
            if(arr[i]<arr[j]){
                leader = false;
                break;
            }
        }
        if(leader==true){
            ans.push_back(arr[i]);
        }
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> result = ArrayLeader(arr , n);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
}


// optimal approach 

vector<int> superiorElements(vector<int> &a) {
    vector<int> ans;
    int maxi = INT_MIN;
    int n = a.size();

    for (int i = n - 1; i >= 0; i--) {
        if (a[i] > maxi) {
            ans.push_back(a[i]);
        }
        maxi = max(maxi, a[i]);
    }

    sort(ans.begin(), ans.end());
    return ans;
}
