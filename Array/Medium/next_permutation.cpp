// brute force approach 

// optimal approach 
#include<bits/stdc++.h>
using namespace std;
vector<int> nextpermutation(vector<int>&arr){
    int ind =-1;
    int n = arr.size();
    for(int i=n-2;i>=0;i--){
        if(arr[i]<arr[i+1]){
            ind=i;
            break;
        }
    }
    if(ind==-1){
        reverse(arr.begin() , arr.end());
        return arr;
    }

    for(int i=n-1;i>ind;i--){
        if(arr[i]>arr[ind]){
            swap(arr[ind] , arr[i]);
            break;
        }
    }
    reverse(arr.begin() + ind + 1 , arr.end());
    return arr;
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> result = nextpermutation(arr);
     for (int x : result) cout << x << " ";
    cout << "\n";
}