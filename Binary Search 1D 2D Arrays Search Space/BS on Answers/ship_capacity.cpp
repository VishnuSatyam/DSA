// brute force 
#include<bits/stdc++.h>
using namespace std;
int fun(vector<int>&weights , int cap){
    int days = 1 , load =0;
    for(int i=0;i<weights.size();i++){
        if(load + weights[i]>cap){
            days+=1;
            load = weights[i];
        }
        else{
            load+=weights[i];
        }
    }
    return days;
}
int capacity(vector<int>&weights , int days){
    int maxi = *max_element(weights.begin() , weights.end());
    int sum=0;
    for(int i=0;i<weights.size();i++){
        sum+=weights[i];
    }
    for(int cap=maxi;cap<=sum;cap++){
        int daysReq = fun(weights , cap);
        if(daysReq<=days){
            return cap;
        }
    }
    return -1;
}

// optimal approach 


int findDays(vector<int>&weights , int cap){
    int days = 1 , load =0;
    for(int i=0;i<weights.size();i++){
        if(load + weights[i]>cap){
            days+=1;
            load = weights[i];
        }
        else{
            load+=weights[i];
        }
    }
    return days;
}

int leastWeightCapacity(vector<int>& weights, int d) {
    int low = *max_element(weights.begin(), weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0);
    
    while(low <= high) {
        int mid = low + (high - low) / 2;
        int numberOfDays = findDays(weights, mid);
        
        if(numberOfDays <= d) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    
    return low;
}