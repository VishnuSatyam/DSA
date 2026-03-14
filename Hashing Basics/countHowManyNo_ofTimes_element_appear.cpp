// // brute force approach  .. here time complexity will be O(n)

// #include<bits/stdc++.h>
// using namespace std;
// int counting(vector<int>arr , int num){
//     int count=0;
//     for(int i=0;i<arr.size();i++){
//         if(arr[i]==num){
//             count+=1;
//         }
//     }
//     return count;
// }

// int main(){
//     int num;
//     int n;
//     cin>>num>> n;
//     vector<int>arr(n);
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     cout<<counting(arr , num);
// }



// so we will use Hashing to solve this problem with which we can do it much faster way
// #include<bits/stdc++.h>
// using namespace std;

// int main() {
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for(int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }
    
//     // precompute
//     vector<int> hash(13, 0);
//     for(int i = 0; i < n; i++) {
//         hash[arr[i]] += 1;
//     }
    
//     int q;
//     cin >> q;
//     while(q--) {
//         int number;
//         cin >> number;
//         // fetch
//         cout << hash[number] << endl;
//     }
    
//     return 0;
// }
//  Note in above example we first took input of no of array then we input array then we took input of no of elements we wanna count then we entered thse elements 


// if we want to  get how many times a character appears we can do it as well wr just need to take the ascii values of characters into consideration

#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    //precomputing 
    int hash[256]={0};
    for(int i=0;i<s.size();i++){
        hash[s[i]]++;
    }
    //fetch
    int q;
    cin>>q;
    while(q--){
        char c;
        cin>>c;
        cout<<hash[c]<<endl;
    }
    return 0;
}
// here we first took input of the string then we took input of character we wanna count then we entered those characters  