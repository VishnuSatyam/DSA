// naive brute force approach 

#include<bits/stdc++.h>
using namespace std;
int CountInversion(vector<int>arr , int n){
    int count =0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]) count++;
        }
    }
    return count;
}

//optimal approach using merge sort 

#include <bits/stdc++.h>
using namespace std;

long long mergeAndCount(vector<int>& arr, int low, int mid, int high) {
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    long long cnt = 0;

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left++]);
        } else {
            temp.push_back(arr[right++]);
            cnt += (mid - left + 1); // count inversions
        }
    }

    while (left <= mid) temp.push_back(arr[left++]);
    while (right <= high) temp.push_back(arr[right++]);

    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }

    return cnt;
}

long long mergeSortAndCount(vector<int>& arr, int low, int high) {
    if (low >= high) return 0;

    int mid = low + (high - low) / 2;
    long long cnt = 0;

    cnt += mergeSortAndCount(arr, low, mid); //Give me inversions inside left half
    cnt += mergeSortAndCount(arr, mid + 1, high);  //Give me inversions inside right half
    cnt += mergeAndCount(arr, low, mid, high);

    return cnt;
}

long long CountInversion(vector<int>& arr) {
    return mergeSortAndCount(arr, 0, arr.size() - 1);
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << CountInversion(arr) << endl;

    return 0;
}