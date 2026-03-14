#include <bits/stdc++.h>
using namespace std;

int counter = 0;

void myFunction() {
    if (counter == 5) {
        return; // stop recursion
    }
    counter++;
    cout << "Function call number: " << counter << endl;
    myFunction(); // recursive call
}

int main() {
    myFunction(); // just call it
    cout << "Total calls: " << counter << endl;
    return 0;
}
