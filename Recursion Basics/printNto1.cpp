#include <bits/stdc++.h>
using namespace std;

void printName(int i , int n) {
    if (i<1) return;  // base case
    cout << i << endl;
    printName(i-1,n);    // reduce and call again
}

int main() {
    int n;
    cin>>n;
    printName(n,n);
    return 0;
}