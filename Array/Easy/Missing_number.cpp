// #include <bits/stdc++.h>
// using namespace std;

// int Missing_Num(vector<int> &arr, int n) {
//     for (int i = 0; i <= n; i++) {     
//         bool flag = 0;
//         for (int j = 0; j < n; j++) { 
//             if (arr[j] == i) {         
//                 flag = 1;
//                 break;
//             }
//         }
//         if (flag == 0) {               
//             return i;
//         }
//     }
//     return -1; 
// }

// int main() {
//     vector<int> arr = {3, 0, 1};
//     int n = arr.size();
//     cout << "Missing Number: " << Missing_Num(arr, n);
// }



// better Approach using the hashing 


// #include <bits/stdc++.h>
// using namespace std;
// int Missing_Num(vector<int> &arr, int n) {
//     vector<int> hash(n + 1, 0);
//     for (int i = 0; i < n; i++) {
//         hash[arr[i]] = 1;
//     }
//     for (int i = 0; i <= n; i++) {
//         if (hash[i] == 0) {
//             return i;
//         }
//     }
//     return -1;
// }

// int main() {
//     int n;
//     cout << "Enter size of array: ";
//     cin >> n;
//     vector<int> arr(n);
//     cout << "Enter " << n << " elements: ";
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }
//     cout << "Missing Number: " << Missing_Num(arr, n);
// }


// optimal approach using the sum 


// #include <bits/stdc++.h>
// using namespace std;
// int Missing_Num(vector<int> &arr, int n){
//     int sum = n*(n+1)/2;
//     int s2=0;
//     for(int i=0;i<n;i++){
//         s2+=arr[i];
//     }
//     return (sum-s2);
// }

// int main() {
//     int n;
//     cout << "Enter size of array: ";
//     cin >> n;
//     vector<int> arr(n);
//     cout << "Enter " << n << " elements: ";
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }
//     cout << "Missing Number: " << Missing_Num(arr, n);
// }




#include <bits/stdc++.h>
using namespace std;
    int missingNumber(vector<int> &a, int N) {
    int xor1 = 0, xor2 = 0;
    int n = N - 1;
    for (int i = 0; i < n; i++) {
        xor2 = xor2 ^ a[i];
        xor1 = xor1 ^ (i + 1);
    }
    xor1 = xor1 ^ N;
    return xor1 ^ xor2;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Missing Number: " << missingNumber(arr, n);
}