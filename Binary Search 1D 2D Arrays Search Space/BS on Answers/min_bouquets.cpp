// brute force 
#include<bits/stdc++.h>
using namespace std;

bool possible(const vector<int>& arr , int m , int k , int day){
    int count = 0 , bouquet = 0;

    for(int i = 0; i < arr.size(); i++){
        if(arr[i] <= day) 
            count++;
        else{
            bouquet += count / k;
            count = 0;
        }
    }

    bouquet += count / k;

    return bouquet >= m;
}

int minDays(vector<int>& bloomDay, int m, int k) {
    long long totalNeeded = 1LL * m * k;

    if (totalNeeded > bloomDay.size())
        return -1;

    int minDay = *min_element(bloomDay.begin(), bloomDay.end());
    int maxDay = *max_element(bloomDay.begin(), bloomDay.end());

    for (int day = minDay; day <= maxDay; day++) {
        if (possible(bloomDay, m, k, day))
            return day;
    }

    return -1;
}


//optimal using bs

bool possible(const vector<int>& arr , int m , int k , int day){
    int count = 0 , bouquet = 0;

    for(int i = 0; i < arr.size(); i++){
        if(arr[i] <= day) 
            count++;
        else{
            bouquet += count / k;
            count = 0;
        }
    }

    bouquet += count / k;

    return bouquet >= m;
}

int minDays(vector<int>& bloomDay, int m, int k){
    long long totalNeeded = 1LL * m * k;

    if (totalNeeded > bloomDay.size()){
        return -1;
    }

    int mini = INT_MAX , maxi = INT_MIN;

    for(int i = 0; i < bloomDay.size(); i++){
        mini = min(mini , bloomDay[i]);
        maxi = max(maxi , bloomDay[i]);
    }

    int low = mini , high = maxi;

    while(low <= high){
        int mid = low + (high - low) / 2;

        if(possible(bloomDay , m , k , mid)){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }

    return low;
}