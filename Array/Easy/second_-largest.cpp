// using the brute force approach ... time complexity at worst case will be O(n )

// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n;
//     cin>>n;
//     vector<int> arr(n);
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
// //     sort(arr.begin(), arr.end());
//     int largest = arr[n-1];
//     int second_largest = -1;
//     for(int i=n-2;i>=0;i--){
//         if(arr[i]!=largest){
//         second_largest=arr[i];
//             break;
//         }
//     }
//     cout<<second_largest;
// }


// Better approach tc is O(2n)

// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n;
//     cin>>n;
//     vector<int> arr(n);
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     int largest = INT_MIN;
//     int second_largest = INT_MIN;
//     for(int i=0;i<n;i++){
//         if(arr[i]>largest){
//             largest=arr[i];
//         }
//     }
    
//     for(int i=0;i<n;i++){
//         if(arr[i]>second_largest && arr[i]!=largest){
//             second_largest=arr[i];
//         }

       
//     }
//      cout<<second_largest;
// }


// optimized approach with O(n ) tc 


#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int largest = INT_MIN;
    int second_largest = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (arr[i] > largest) {
            // current element becomes new largest
            // old largest becomes second largest
            second_largest = largest;
            largest = arr[i];
        } 
        else if (arr[i] > second_largest && arr[i] != largest) {   // to understand why else condition is necessary take arr = { 10 , 5 , 8} and dry run 
            // current element is between largest and second_largest
            second_largest = arr[i];
        }
    }

    if (second_largest == INT_MIN) {
        cout << "No second largest element (all equal)" << endl;
    } else {
        cout << "Second largest element: " << second_largest << endl;
    }

    return 0;
}

