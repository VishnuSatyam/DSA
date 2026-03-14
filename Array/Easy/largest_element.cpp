// // brute force approach
// #include<bits/stdc++.h>
// using namespace std;
// int main() {
//     vector<int> arr = {10, 3, 45, 7, 22, 18};

//     sort(arr.begin(), arr.end());

//     int largest = arr[arr.size() - 1];

//     cout << "The largest element is: " << largest << endl;

//     return 0;
// }

// we can use better approch by using the optimal approach


#include<bits/stdc++.h>
using namespace std;

int  largestElement(vector<int>&arr , int n){
    int largest = arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>largest){
            largest = arr[i];
        }
    }
    return largest;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<largestElement(arr , n);
}