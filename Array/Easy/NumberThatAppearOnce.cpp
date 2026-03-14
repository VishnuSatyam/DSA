// Brute force approach 

// #include<bits/stdc++.h>
// using namespace std;
// int AppearOnce(vector<int> &arr , int n){
//     for(int i=0;i<n;i++){
//         int num=arr[i];
//         int count=0;
//         for(int j=0;j<n;j++){
//             if(arr[j]==num){
//                 count++;
//             }
//         }
//         if(count==1){
//             return num;
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
//     int result=AppearOnce(arr , n);
//     cout<<result<<"";
//     return 0;
// }



// better approach 


// #include <bits/stdc++.h>
// using namespace std;

// int AppearOnce(vector<int> &arr, int n) {
//     int hash[100001] = {0}; // assuming numbers ≤ 100000

//     for (int i = 0; i < n; i++) {
//         hash[arr[i]]++;
//     }

//     for (int i = 0; i < n; i++) {
//         if (hash[arr[i]] == 1) {
//             return arr[i];
//         }
//     }

//     return -1;
// }

// int main() {
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for (int i = 0; i < n; i++) cin >> arr[i];

//     cout << AppearOnce(arr, n);
// }


// better using the map 

// #include <bits/stdc++.h>
// using namespace std;

// int AppearOnce(vector<int> &arr, int n) {
//     unordered_map<int, int> mp;

//     for (int i = 0; i < n; i++) {
//         mp[arr[i]]++;
//     }

//     for (auto it : mp) {
//         if (it.second == 1) {
//             return it.first;
//         }
//     }

//     return -1;
// }

// int main() {
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for (int i = 0; i < n; i++) cin >> arr[i];

//     cout << AppearOnce(arr, n);
// }


// optimal approach using the XOR 



#include <bits/stdc++.h>
using namespace std;

int AppearOnce(vector<int> &arr, int n){
    int xorr =0;
    for(int i=0;i<arr.size();++i){
        xorr=xorr^arr[i];
    }
    return xorr;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n); 
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << AppearOnce(arr, n);
}