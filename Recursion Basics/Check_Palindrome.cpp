#include<bits/stdc++.h>
using namespace std;

bool checkPalindrome(vector<int>&arr, int i, int n){
    if(i >= n/2){
        return true;
    }
    if(arr[i] != arr[n-i-1]){
        return false;
    }
    return checkPalindrome(arr, i+1, n);
}

int main(){
    int n;
    cin >> n;
    vector<int>arr;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }
    
    bool result = checkPalindrome(arr, 0, n);
    
    // Print the result
    if(result){
        cout << "The array is a palindrome" << endl;
    } else {
        cout << "The array is not a palindrome" << endl;
    }
    
    return 0;
}