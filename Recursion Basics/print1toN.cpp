#include <bits/stdc++.h>
using namespace std;

void printName(int i , int n) {
    if (i>n) return;  // base case
    cout << i << endl;
    printName(i+1,n);    // reduce and call again
}

int main() {
    int n;
    cin>>n;
    printName(1,n);
    return 0;
}