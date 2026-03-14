#include<bits/stdc++.h>
using namespace std;
void insertionSort(int a[] , int i , int n){
    if(i==n) return;
    int j=i;
    while(j>0&&a[j]<a[j-1]){
        swap(a[j] , a[j-1]);
        j--;
    }
    insertionSort(a , i+1 , n);
}
int main(){
    int n=5;
    int a[]={5,4,3,2,1};
    insertionSort(a ,0, n );
    for(int i=0;i<n;i++){
        cout<<a[i]<<endl;
    }
}