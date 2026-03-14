#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n <= 1) {
        cout << "Not Prime";
        return 0;
    }

    bool isPrime = true;
    for (int i = 2; i * i <= n; i++) {   // only check till sqrt(n)
        if (n % i == 0) {
            isPrime = false;
            break;
        }
    }

    if (isPrime) cout << "Prime";
    else cout << "Not Prime";

    return 0;
}
