#include<bits/stdc++.h>
using namespace std;
void BubbleSort(vector<int> &arr , int n){
    for(int i=(n-1);i>=1;i--){
        bool didSwap = false;
        for(int j=0;j<=i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
                didSwap=true;
            }
        }
        if(didSwap==false){
            break;
        }
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
    BubbleSort(arr,n);
}