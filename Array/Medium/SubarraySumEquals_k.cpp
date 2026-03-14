// optimal approach

#include <bits/stdc++.h>
using namespace std; 

int findAllSubarraysWithGivenSum(vector<int> &arr, int k) {

    unordered_map<int,int> mpp;
    mpp[0] = 1;  // prefix sum = 0 already seen once

    int preSum = 0, cnt = 0;

    for(int i = 0; i < arr.size(); i++) {

        preSum += arr[i];

        int remove = preSum - k;

        cnt += mpp[remove];

        mpp[preSum]++;
    }

    return cnt;
}

int main() {
    int n, k;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter target sum k: ";
    cin >> k;

    int result = findAllSubarraysWithGivenSum(arr, k);

    cout << "Number of subarrays with sum " << k << " = " << result << endl;

    return 0;
}



/*   Note :  mpp[0] = 1; is one of the most important lines in prefix-sum + hashmap technique.
Let me explain it very clearly.

✅ Why do we write mpp[0] = 1; ?

We are counting subarrays whose sum = k.

We maintain:

preSum = sum of elements from arr[0] to arr[i]

We need to find how many times a prefix sum (preSum - k) has appeared before.
Because:

If 
𝑝
𝑟
𝑒
𝑆
𝑢
𝑚
−
𝑜
𝑙
𝑑
𝑃
𝑟
𝑒
𝑆
𝑢
𝑚
=
𝑘
⇒
subarray sum = k
If preSum−oldPreSum=k⇒subarray sum = k
🔍 Now the main doubt: what does mpp[0] = 1 do?

This means:

We have seen a prefix sum of 0 exactly once before the array starts.

Before starting the loop, we assume:

prefix sum = 0 occurs once


Why??
Because this helps us count subarrays starting from index 0.

🎯 Example to understand
arr = [3, 1, 2, 4], k = 3

Before loop:

mpp = { 0 : 1 }


Now iterate:

i = 0

preSum = 3

We check:

remove = preSum - k = 3 - 3 = 0
cnt += mpp[0]   → cnt = 1


WHY?

Because prefix sum = 3 itself equals k.

This corresponds to subarray:

[3] → sum = 3


This subarray starts at index 0, and we detect it ONLY because we inserted:

mpp[0] = 1


Without this line, we would miss all subarrays starting from the beginning.

✔️ Therefore: Purpose of mpp[0] = 1
It allows counting subarrays whose sum = k and begin at index 0.
Without it → WRONG answer.
🔑 Summary
Line	Meaning
mpp[0] = 1;	Store that prefix sum zero occurs once: helps detect subarrays starting at index 0.
Useful When	preSum == k
Effect	Counts subarray [0…i] correctly

If you want, I can also give a dry run of the entire code with a sample input.



*/