//print from 1 to n

#include <bits/stdc++.h>
using namespace std;

void printName(int i , int n) {
    if (i<1) return;  // base case
    printName(i-1,n);
    cout << i << endl;
        // reduce and call again
}

int main() {
    int n;
    cin>>n;
    printName(n,n);
    return 0;
}

//  for printing from n to 1 using backtarcking concept


// #include <bits/stdc++.h>
// using namespace std;

// void printName(int i , int n) {
//     if (i>n) return;  // base case
//     printName(i+1,n);
//     cout << i << endl;
//         // reduce and call again
// }

// int main() {
//     int n;
//     cin>>n;
//     printName(1,n);
//     return 0;
// }