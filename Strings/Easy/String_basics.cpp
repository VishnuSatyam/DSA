// This program demonstrates how to convert a string of digits into an integer using a simple loop and character manipulation.
#include <iostream>
using namespace std;

int main() {
    string s = "1234";
    int num = 0;

    for(char c : s) {
        num = num * 10 + (c - '0');
    }

    cout << num;  // 1234
}

// using stl functions conversion of string to int

#include <iostream>
using namespace std;

int main() {
    string s = "123";

    int num = stoi(s);

    cout << num + 5;  // 128
}

