#include <bits/stdc++.h>
using namespace std;

void printS(int ind, vector<int>& ds, int currSum, int target, int arr[], int n) {
    
    if (ind == n) {
        if (currSum == target) {
            for (int x : ds) cout << x << " ";
            cout << endl;
        }
        return;
    }

    if (currSum > target) return;

    // take
    ds.push_back(arr[ind]);
    currSum += arr[ind];

    printS(ind + 1, ds, currSum, target, arr, n);

    // backtrack
    currSum -= arr[ind];
    ds.pop_back();

    // not take
    printS(ind + 1, ds, currSum, target, arr, n);
}

int main() {
    int arr[] = {1, 2, 1};
    int n = 3;
    int target = 2;

    vector<int> ds;
    printS(0, ds, 0, target, arr, n);

    return 0;
}



// if we just need to print one suubsequence equal to sum 


#include <bits/stdc++.h>
using namespace std;

bool printS(int ind, vector<int>& ds, int currSum, int target, int arr[], int n) {
    
    if (ind == n) {
        if (currSum == target) {
            for (int x : ds) cout << x << " ";
            cout << endl;
            return true; // ✅ stop everything
        }
        return false;
    }

    // take
    ds.push_back(arr[ind]);
    if (printS(ind + 1, ds, currSum + arr[ind], target, arr, n))
        return true;

    // backtrack
    ds.pop_back();

    // not take
    if (printS(ind + 1, ds, currSum, target, arr, n))
        return true;

    return false;
}

int main() {
    int arr[] = {1, 2, 1};
    int n = 3;
    int target = 2;

    vector<int> ds;
    printS(0, ds, 0, target, arr, n);

    return 0;
}