#include <iostream>
using namespace std;

int main() {
    int a = 5, b = 10;

    cout << "Before swap: a = " << a << ", b = " << b << '\n';

    a ^= b;
    b ^= a;
    a ^= b;

    cout << "After swap: a = " << a << ", b = " << b << '\n';

    return 0;
}