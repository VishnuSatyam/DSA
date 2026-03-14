//lower bound 

#include <bits/stdc++.h>
using namespace std;

int myLowerBound(vector<int>& arr, int n, int target) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= target) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;

    int target = 5;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;

    int result = myLowerBound(arr, n, target);

    if (result == n) {
        cout << "No element >= " << target << endl;
    } else {
        cout << "Lower bound index: " << result << endl;
        cout << "Value: " << arr[result] << endl;
    }
}

// with use of stl we can directly get lower bound with : lb = lower_bound(arr.begin(), arr.end() , n).. this will return an iterator pointing to that index  ,, to get that index  we can just subtract beginner iterator..->  lb = lower_bound(arr.begin(), arr.end() , n)-arr.begin()


// upper bound 

int upperBound(vector<int>& arr, int x, int n){
    int low = 0, high = n - 1;
    int ans = n;
    while(low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if(arr[mid] > x) {
            ans = mid;
            // look for more small index on left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look for right
        }
    }
    return ans;
}

// with use of stl we can directly get lower bound with : ub = upper_bound(arr.begin(), arr.end() , n).. this will return an iterator pointing to that index  ,, to get that index  we can just subtract beginner iterator..->  ub = upper_bound(arr.begin(), arr.end() , n)-arr.begin()