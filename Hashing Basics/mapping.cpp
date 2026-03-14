#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    //precompute
    map<int ,int>mpp;
    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
    }

     //fetch


     // to check if sorted 
     for(auto it:mpp){
        cout<<it.first<<"->"<<it.second<<endl;
     } 
    int q;
    cin>>q;
    while(q--){
        int number;
        cin>>number;
        cout<<mpp[number]<<endl;
    }
   
}

// time complexity will we O(logn) as it store keys in sorted order but if we do unordere map it will be O(1) avg TC . we just need to write unordered map<int , int>for worst case will be linear

// we can also use map for the character as well map<char,int>