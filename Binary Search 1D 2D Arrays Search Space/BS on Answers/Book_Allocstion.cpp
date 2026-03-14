#include <bits/stdc++.h>
using namespace std;

bool canAllocate(vector<int> &arr, int students, int maxPages) {
    int studentCount = 1;
    int pagesSum = 0;

    for (int i = 0; i < arr.size(); i++) {
        if (pagesSum + arr[i] <= maxPages) {
            pagesSum += arr[i];
        } else {
            studentCount++;
            pagesSum = arr[i];

            if (studentCount > students)
                return false;
        }
    }

    return true;
}

int bookAllocation(vector<int> &arr, int students) {
    if (students > arr.size())
        return -1;

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canAllocate(arr, students, mid)) {
            high = mid - 1;   // try smaller max
        } else {
            low = mid + 1;    // increase max
        }
    }

    return low;
}