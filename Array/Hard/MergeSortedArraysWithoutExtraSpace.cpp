//brute force using extra space 

#include<bits/stdc++.h>
using namespace std;
void merge(long long arr1[], long long arr2[],int n, int m){
    long long arr3[n+m];
    int left =0;
    int right =0;
    int index=0;
    while(left<n &&  right<m){
        if(arr1[left]<=arr2[right]){
            arr3[index]=arr1[left];
            left++ , index++;
        }
        else{
            arr3[index]=arr2[right];
            right++ , index++;
        }
    }
    while(left<n){
        arr3[index++]=arr2[left++];
    }
    while(right<m){
        arr3[index++]=arr2[right++];
    }
    for(int i=0;i<n+m;i++){
        if(i<n) arr1[i] = arr3[i];
        else arr2[i-n]=arr3[i];
    }
}

// optimal  approach 1

void merge(long long arr1[], long long arr2[],int n, int m){
    int left=n-1;
    int right=0;
    while(left>=0 && right<m){
        if(arr1[left]>arr2[right]){
            swap(arr1[left], arr2[right]);
            left-- , right++;
        }
        else{
            break;
        }
    }
    sort(arr1 , arr1+n);    /* note line arr1        → address of arr1[0]
                               arr1 + n    → address of arr1[n] (one past last element)
                                     */
    sort(arr2 , arr2+m);
}

// optimal approach 2

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void swapIfGreater(long long arr1[], long long arr2[], int i, int j) {
        if (arr1[i] > arr2[j]) {
            swap(arr1[i], arr2[j]);
        }
    }

public:
    void merge(long long arr1[], long long arr2[], int n, int m) {
        int len = n + m;

        // initial gap
        int gap = (len / 2) + (len % 2);  // ceil(len / 2)

        while (gap > 0) {
            int left = 0;
            int right = left + gap;

            while (right < len) {

                // left in arr1, right in arr2
                if (left < n && right >= n) {
                    swapIfGreater(arr1, arr2, left, right - n);  // for arr2 index again start from zero so to get that we do right - length of arr1 .
                }
                // both in arr2
                else if (left >= n) {
                    swapIfGreater(arr2, arr2, left - n, right - n);  // for arr2 index again start from zero so to get that we do right - length of arr1 and left-len of arr1 
                }
                // both in arr1
                else {
                    swapIfGreater(arr1, arr1, left, right);
                }

                left++;
                right++;
            }

            if (gap == 1) break;

            gap = (gap / 2) + (gap % 2);  // reduce gap
        }
    }
};
