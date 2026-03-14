//  // naive brute force apprach 

//  #include<bits/stdc++.h>
//  using namespace std;
//  int longestSubarraySum(vector<int> arr , int n , int k){
//     int maxLen=0;
//     for(int i=0;i<n;i++){
//         for(int j=i;j<n;j++){
//             int sum=0;
//             for(int t=i;t<=j;t++){
//                 sum+=arr[t];
//             }
//             if(sum==k){
//                 maxLen=max(maxLen , j-i+1);
//             }
//         }
//     }
//     return maxLen;
//  }
//  int main(){
//     int n;
//     cin>>n;
//     vector<int> arr(n);
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     int k;
//     cout<<"enter the value of k";
//     cin>>k;

//     int result=longestSubarraySum(arr , n , k);
//     cout<<result;

//  }
 


 // better brute force approach 

//  #include<bits/stdc++.h>
//  using namespace std;
//  int longestSubarraySum(vector<int> arr , int n , int k){
//     int maxLen=0;
//     for(int i=0;i<n;i++){
//          int sum=0;
//         for(int j=i;j<n;j++){
//            sum+=arr[j];
//             if(sum==k){
//                 maxLen=max(maxLen , j-i+1);
//             }
//         }
//     }
//     return maxLen;
//  }

//  int main(){
//     int n;
//     cin>>n;
//     vector<int> arr(n);
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     int k;
//     cout<<"enter the value of k";
//     cin>>k;

//     int result=longestSubarraySum(arr , n , k);
//     cout<<result;

//  }


 // better approach using hashing and this is optimal as well if array contain +ve , -ve and zeros zeros 


#include <bits/stdc++.h>
using namespace std;

int longestSubarrayWithSumK(vector<int>& a, long long k) {
    int left = 0, right = 0;
    long long sum = a[0];
    int maxLen = 0;
    int n = a.size();
    
    while (right < n) {
        while (left <= right && sum > k) {
            sum -= a[left];
            left++;
        }

        if (sum == k) {
            maxLen = max(maxLen, right - left + 1);
        }

        right++;
        if (right < n) sum += a[right];
    }
    
    return maxLen;
}

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long k;
    cout << "Enter value of k: ";
    cin >> k;

    int result = longestSubarrayWithSumK(arr, k);
    cout << "Longest subarray length = " << result << endl;

    return 0;
}