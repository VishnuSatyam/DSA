// // brute force approach 
// #include <bits/stdc++.h>
// using namespace std;

// vector<int> twosum(vector<int> arr, int n, int target) {
//     for (int i = 0; i < n; i++) {
//         for (int j = i + 1; j < n; j++) {
//             if (arr[i] + arr[j] == target) {
//                 return {i, j};
//             }
//         }
//     }
//     return {-1, -1};
// }

// int main() {
//     vector<int> arr = {2, 7, 11, 15};
//     int target = 9;
//     vector<int> ans = twosum(arr, arr.size(), target);
//     cout << ans[0] << " " << ans[1];
// }




// optimal approach





#include <bits/stdc++.h>
using namespace std;

vector<int> twosum(vector<int> arr, int n, int target) {
    map<int, int> mpp;
    for (int i = 0; i < n; i++) {
        int a = arr[i];
        int more = target - a;
        if (mpp.find(more) != mpp.end()) {
            return {mpp[more], i};
        }
        mpp[a] = i;
    }
    return {-1, -1};
}

int main() {
    vector<int> arr = {2, 7, 11, 15};
    int target = 9;
    vector<int> ans = twosum(arr, arr.size(), target);
    cout << ans[0] << " " << ans[1];
}





// optimal approach if it just ask to yes or no 

// string read(int n, vector<int> book, int target)
// {
//     int left = 0, right = n-1;
//     sort(book.begin(), book.end());
//     while(left < right) {
//         int sum = book[left] + book[right];
//         if(sum == target) {
//             return "YES";
//         }
//         else if(sum < target) left++;
//         else right--;
//     }
//     return "NO";
// }
