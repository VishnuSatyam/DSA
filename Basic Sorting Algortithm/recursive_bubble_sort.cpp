#include<bits/stdc++.h>
using namespace std;
void bubblesort(int input[] , int endIndex){
    if(endIndex==0){
        return;
    }
    for(int i=0;i<endIndex;i++){
        if(input[i]>input[i+1]){
            int temp=input[i];
            input[i]=input[i+1];
            input[i+1]=temp;
        }
    }
    bubblesort(input , endIndex-1);
}
int main(){
    int arr[]={5,95,1,4,2};
    bubblesort(arr , 4);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<endl;
    }
}