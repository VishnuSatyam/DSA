// // brute force approach 
// #include<bits/stdc++.h>
// using namespace std;
// int Majority_Element(vector<int>arr , int n){
//     for(int i=0;i<n;i++){
//         int count=0;
//         for(int j=0;j<n;j++){
//             if(arr[i]==arr[j]){
//                 count++;
//             }
//             if(count>n/2){
//                 return arr[i];
//             }
//         }
//     }
//     return -1;
// }
// int main(){
//     int n;
//     cin>>n;
//     vector<int>arr(n);
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     int result = Majority_Element(arr , n);
//     cout<<result;
// }




// better approach using hashmap




// #include<bits/stdc++.h>
// using namespace std;
// int Majority_Element(vector<int>arr , int n){
//     map<int,int> mpp;
//     for(int i=0;i<n;i++){
//        mpp[arr[i]]++;
//     }
//     for(auto it: mpp){
//         if(it.second>n/2){
//             return it.first;
//         }
//     }
//     return -1;
// }
// int main(){
//     int n;
//     cin>>n;
//     vector<int>arr(n);
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     int result = Majority_Element(arr , n);
//     cout<<result;
// }




// optimal approach using the moore's voting algorithm

#include<bits/stdc++.h>
using namespace std;
int Majority_Element(vector<int>arr , int n){
    int cnt=0;
    int el;
    for(int i=0;i<n;i++){
        if(cnt==0){
            cnt=1;
            el=arr[i];
        }
        else if(arr[i]==el){
            cnt++;
        }
        else{
            cnt--;
        }
    }
    int cnt1=0;
    for(int i=0;i<n;i++){
        if(arr[i]==el) cnt1++;
    }
    if(cnt1>n/2){
        return el;
    }
    return -1;
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int result = Majority_Element(arr , n);
    cout<<result;
}

// optimal approach using boyre moore for majority element II 


vector<int> majorityElement(vector<int>& arr, int n) {
    int cnt1 = 0, cnt2 = 0;
    int el1 = INT_MIN, el2 = INT_MIN;

    // Step 1: find candidates
    for (int i = 0; i < n; i++) {
        if (cnt1 == 0 && arr[i] != el2) {
            el1 = arr[i];
            cnt1 = 1;
        }
        else if (cnt2 == 0 && arr[i] != el1) {
            el2 = arr[i];
            cnt2 = 1;
        }
        else if (arr[i] == el1) {
            cnt1++;
        }
        else if (arr[i] == el2) {
            cnt2++;
        }
        else {
            cnt1--;
            cnt2--;
        }
    }

    // Step 2: verify the counts
    int c1 = 0, c2 = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == el1) c1++;
        else if (arr[i] == el2) c2++;
    }

    vector<int> ans;
    if (c1 > n/3) ans.push_back(el1);
    if (c2 > n/3) ans.push_back(el2);

    return ans;
}
