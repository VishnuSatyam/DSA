// uderstanding using longest subrrray sum  .. maximum subarray sum  of size k . 

// brute force approach

#include<bits/stdc++.h>
using namespace std;

int maxSubarraySum(vector<int> &arr, int k){

    int n = arr.size();
    int maxSum = INT_MIN;

    for(int i = 0; i <= n - k; i++){

        int sum = 0;

        for(int j = i; j < i + k; j++){
            sum += arr[j];
        }

        maxSum = max(maxSum, sum);
    }

    return maxSum;
}

int main(){

    vector<int> arr = {1,2,3,4,5};
    int k = 3;

    cout << maxSubarraySum(arr, k);

}


//optimal approach using sliding window
#include<bits/stdc++.h>
using namespace std;

int maxSubarraySum(vector<int> &arr, int k){

    int n = arr.size();
    int maxsum = INT_MIN;

    int i = 0, j = 0;
    int sum = 0;

    while(j < n){

        sum += arr[j];

        if(j - i + 1 < k){
            j++;
        }

        else if(j - i + 1 == k){

            maxsum = max(maxsum, sum);

            sum = sum - arr[i];

            i++;
            j++;
        }
    }

    return maxsum;
}

int main(){

    vector<int> arr = {1,2,3,4,5};
    int k = 3;

    cout << maxSubarraySum(arr, k);
}

// if we only need to include distict subarray then (leetocde 2461):


#include<bits/stdc++.h>
using namespace std;

long long maxSubarraySum(vector<int>& arr, int k) {

    int i = 0, j = 0;
    long long sum = 0;
    long long maxsum = 0;

    unordered_map<int,int> freq;

    while(j < arr.size()){

        sum += arr[j];
        freq[arr[j]]++;

        if(j - i + 1 < k){
            j++;
        }

        else if(j - i + 1 == k){

            if(freq.size() == k){
                maxsum = max(maxsum, sum);
            }

            sum -= arr[i];
            freq[arr[i]]--;

            if(freq[arr[i]] == 0)
                freq.erase(arr[i]);

            i++;
            j++;
        }
    }

    return maxsum;
}

int main(){

    vector<int> arr = {1,5,4,2,9,9,9};
    int k = 3;

    cout << maxSubarraySum(arr,k);
}