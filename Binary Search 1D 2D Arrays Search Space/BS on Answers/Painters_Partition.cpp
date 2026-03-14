#include <bits/stdc++.h>
using namespace std;

bool canPaint(vector<int>& boards, int k, int maxTime) {
    int painters = 1;
    int curr = 0;

    for (int b : boards) {
        if (curr + b <= maxTime) {
            curr += b;
        } else {
            painters++;
            curr = b;
            if (painters > k) return false;
        } 
    }
    return true;
}

int paintersPartition(vector<int>& boards, int k) {
    int low = *max_element(boards.begin(), boards.end());
    int high = accumulate(boards.begin(), boards.end(), 0);

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (canPaint(boards, k, mid))
            high = mid;
        else
            low = mid + 1;
    }

    return low;
}

int main() {
    vector<int> boards = {10,20,30,40};
    int k = 2;

    cout << paintersPartition(boards, k);
}