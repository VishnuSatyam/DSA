#include<bits/stdc++.h>
using namespace std;
int maximumprofit(vector<int> & price){
    int mini= price[0];
    int maxprofit = 0;
    int n=price.size();
    for(int i=0;i<n;i++){
        int cost = price[i]-mini;
        maxprofit = max(maxprofit , cost);
        mini = min(mini , price[i]);   
    }
    return maxprofit;
}
int main(){
    int n;
    cin>>n;
    vector<int> price(n);
    for(int i=0;i<n;i++){
        cin>>price[i];
    }
    int result = maximumprofit(price);
    cout<<result;
}