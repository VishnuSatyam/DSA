#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
//     int dup=n;
//     int sum=0;
//     while(n>0){
//         int lastDig=n%10;
//         sum=sum+(lastDig*lastDig*lastDig);
//         n=n/10;
    
//     }
//     if(dup==sum){
//         cout<<"is armstrong num";
//     }
//     else {
//         cout<<"not armstrong";
//     }
// }

// for any digits 
int digits=to_string(n).length();
int dup=n;
    int sum=0;
    while(n>0){
        int lastDig=n%10;
        sum=sum+(lastDig*lastDig*lastDig);
        n=n/10;
    
    }
    if(dup==sum){
        cout<<"is armstrong num";
    }
    else {
        cout<<"not armstrong";
    }
}
