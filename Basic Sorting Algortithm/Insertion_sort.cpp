#include<bits/stdc++.h>
using namespace std;
void insertionSort(vector<int> &arr , int n){
    for(int i=1;i<n;i++){
        int j=i;
        while(j>0&& arr[j-1]>arr[j]){
            swap(arr[j-1] , arr[j]);
            j--;
        }
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    insertionSort(arr , n);
    for(int i=0; i<n; i++)
    cout << arr[i] << " ";
    cout << endl;

}
// time complexity is O(n^2) for worst and avg case .