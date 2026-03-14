#include<bits/stdc++.h>
using namespace std;
long long maxSubarraySum(vector<int> arr , int n){
    long long sum=0 , maxi=INT_MIN;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum>maxi){
            maxi=sum;
        }
        if(sum<0){
            sum=0;
        }
    }
    return max(0LL , maxi);
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    long long result = maxSubarraySum(arr , n);
    cout<<result;
}




// if we also need to print that subarray as well 


// #include <bits/stdc++.h>
// using namespace std;

// void maxSubArray(vector<int>& nums) {
//     int n = nums.size();
//     int sum = 0, maxi = INT_MIN;
//     int start = 0, end = 0, tempStart = 0;

//     for (int i = 0; i < n; i++) {
//         sum += nums[i];

//         if (sum > maxi) {
//             maxi = sum;
//             start = tempStart;
//             end = i;
//         }

//         if (sum < 0) {
//             sum = 0;
//             tempStart = i + 1;
//         }
//     }

//     cout << "Maximum Subarray Sum = " << maxi << endl;
//     cout << "Subarray = [ ";
//     for (int i = start; i <= end; i++) cout << nums[i] << " ";
//     cout << "]" << endl;
// }

// int main() {
//     vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
//     maxSubArray(nums);
// }
