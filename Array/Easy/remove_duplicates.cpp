// Brute force approach using the set data structure

// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n;
//     cin>>n;
//     vector<int> arr(n);
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     set<int> st;
//     for(int i=0;i<n;i++){
//         st.insert(arr[i]);
//     }

//     int index = 0;
//     for(auto it: st){
//         arr[index]=it;
//         index++;
//     }
//     arr.resize(index); //shrink vector to contain only unique elements
//     for (int i = 0; i < arr.size(); i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;

// }



// optimal approach using the two pointers 

#include<bits/stdc++.h>
using namespace std;
int removeDuplicates(vector<int>&arr , int n){
    int i=0;
    for(int j=1;j<n;j++){
        if(arr[i]!=arr[j]){
            arr[i+1]=arr[j];
            i++;
        }
    }
    return i+1;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr.begin(), arr.end()); // make sure it’s sorted as this work for sorted array 
    int new_length = removeDuplicates( arr , n);

     arr.resize(new_length); // keep only unique elements

    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}

