#include<bits/stdc++.h>
using namespace std;
void selectionSort(vector<int> &arr , int n){
    for(int i=0;i<=(n-2);i++){
        int minIndex=i;\
        for(int j=i+1;j<=n-1;j++){
            if(arr[j]<arr[minIndex]){
                minIndex=j;
            }
        }
        int temp=arr[minIndex];
        arr[minIndex]=arr[i];
        arr[i]=temp;
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
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
    selectionSort(arr , n);
    
}