#include<bits/stdc++.h>
using namespace std;

int smallestdivisor(vector<int>& arr , int t){
    int maxi = *max_element(arr.begin(), arr.end());

    for(int d = 1; d <= maxi; d++){
        int sum = 0;

        for(int i = 0; i < arr.size(); i++){
            sum += (arr[i] + d - 1) / d;  //ceil(a / b) = (a + b - 1) / b
        }

        if(sum <= t){
            return d;
        }
    }

    return -1;
}

// optimal approach using bs 

int sumByD(vector<int>& arr, int div) {
    int sum = 0;
    for(int i = 0; i < arr.size(); i++) {
        sum += (arr[i] + div - 1) / div; // this is again for ceil value 
    }
    return sum;
}

int smallestDivisor(vector<int>& arr, int limit) {
    int n = arr.size();

    if(limit < n) return -1;

    int low = 1;
    int high = *max_element(arr.begin(), arr.end());

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(sumByD(arr, mid) <= limit) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return low;
}
