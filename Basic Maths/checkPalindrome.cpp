#include <bits/stdc++.h>
using namespace std;

void palindrome(int n) {
    int original = n;   // keep the original number
    int reverse = 0;

    while (n > 0) {
        int lastdig = n % 10;
        reverse = (reverse * 10) + lastdig;
        n /= 10;   // reduce n, otherwise infinite loop
    }

    if (reverse == original) {
        cout << "Number is palindrome";
    } else {
        cout << "Not a palindrome";
    }
}

int main() {
    int n;
    cin >> n;
    palindrome(n);
    return 0;
}
