//parameterized way

#include<bits/stdc++.h>
using namespace std;
// void printSum(int i , int sum){
//     if(i<1){
//         cout<<sum;
//         return;
//     }
//     printSum(i-1 , sum+i);
// }
// int main(){
//     int n;
//     int sum;
//     cin>>n;
//     printSum( n , 0);
// }


// let's take a look at the functional way

int printSum( int n){
    if(n==0){
        return 0;
    }
    return n + printSum(n-1);
}
int main(){
    int n;
    cin>>n;
    cout<<printSum(n);
}