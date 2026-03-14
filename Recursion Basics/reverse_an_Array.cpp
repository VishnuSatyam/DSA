// this one is simple two pointer approach


// #include<bits/stdc++.h>
// using namespace std;
// vector<int> reverse(vector<int>v){
//     int s=0; int e=v.size()-1;
//     while(s<=e){
//         swap(v[s], v[e]);
//         s++;
//         e--;
//     }
//     return v;
// }
// void print(vector<int>v){
//         for(int i=0;i<v.size();i++){
//             cout<<v[i]<<"  ";;
//         }
//     }
    
// int main(){
//     vector<int>v;
//     v.push_back(11);
//     v.emplace_back(7);
//     v.emplace_back(12);
//     v.emplace_back(4);
//     v.emplace_back(18);
//     vector<int>ans=reverse(v);
//     print(ans);
// }



// // using recursion


#include<bits/stdc++.h>
using namespace std;

void reverse(vector<int>&arr, int i, int n){
    if(i>=n/2){
        return;
    }
    swap(arr[i], arr[n-i-1]);
    reverse(arr, i+1, n);
}
int main(){
    int n;
    cin>>n;
    vector<int>arr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    reverse(arr, 0, n);

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}