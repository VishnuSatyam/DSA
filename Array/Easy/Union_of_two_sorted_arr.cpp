// brute force approach using the set 

// #include <bits/stdc++.h>
// using namespace std;

// vector<int> union_array(vector<int> a, vector<int> b) {
//     int n1 = a.size();
//     int n2 = b.size();
//     set<int> st;

//     for (int i = 0; i < n1; i++) {
//         st.insert(a[i]);
//     }
//     for (int i = 0; i < n2; i++) {
//         st.insert(b[i]);
//     }

//     vector<int> uni;
//     for (auto it : st) {
//         uni.push_back(it);
//     }
//     return uni;
// }

// int main() {
//     int n1, n2;
//     cin >> n1;
//     vector<int> a(n1);
//     for (int i = 0; i < n1; i++) {
//         cin >> a[i];
//     }

//     cin >> n2;
//     vector<int> b(n2);
//     for (int i = 0; i < n2; i++) {
//         cin >> b[i];
//     }

//     vector<int> uni = union_array(a, b);
//     for (int i = 0; i < uni.size(); i++) {
//         cout << uni[i] << " ";
//     }
//     return 0;
// }


// optimal approach 

#include<bits/stdc++.h>
using namespace std;
vector<int> sortedArray(vector<int> a , vector<int> b){
    int n1 =  a.size();
    int n2 = b.size();
    int i=0;
    int j=0;
    vector<int> unionArr;
    while(i<n1 && j<n2){
        if(a[i]<=b[j]){
            if(unionArr.size()==0 || unionArr.back()!=a[i]){
                unionArr.push_back(a[i]);
            }
            i++;
        }
        else {
            if(unionArr.size()==0 || unionArr.back()!=b[j]){
                unionArr.push_back(b[j]);
            }
            j++;

        }
    }
     while(i<n1){
            if(unionArr.size()==0 || unionArr.back()!=a[i]){
                unionArr.push_back(a[i]);
            }
            i++;

        }
        while(j<n2){
             if(unionArr.size()==0 || unionArr.back()!=b[j]){
                unionArr.push_back(b[j]);
            }
            j++;
        }
        return unionArr;

}

int main(){
    int n1;
    cin>>n1;
    vector<int>a(n1);
    for(int i=0;i<n1;i++){
        cin>>a[i];
    }
    int n2;
    cin>>n2;
    vector<int>b(n2);
    for(int i=0;i<n2;i++){
        cin>>b[i];
    }
    vector<int> unionArr = sortedArray(a , b);

    for(int i=0;i<unionArr.size();i++){
        cout<<unionArr[i]<<" ";
    }
}