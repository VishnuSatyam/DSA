#include <bits/stdc++.h>
using namespace std;

void printName(int i , int n) {
    if (i>n) return;  // base case
    cout << "Vishnu" << endl;
    printName(i+1,n);    // reduce and call again
}

int main() {
    int n;
    cin>>n;
    printName(1,n);
    return 0;
}
// time complexity is O(n) and stack space is O(n)