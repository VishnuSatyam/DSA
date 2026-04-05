#include<bits/stdc++.h>
using namespace std;

// convert decimal to binary 

#include <bits/stdc++.h>
using namespace std;

string convertToBinary(int n) {
    if (n == 0) return "0";

    string res = "";
    while (n > 0) {
        if (n % 2 == 1) {
            res += '1';
        } else {
            res += '0';
        }
        n = n / 2;
    }

    reverse(res.begin(), res.end());
    return res;
} // tc will be O(n) , and sc will be O(n);


// coonvert binary to decimal 

#include <bits/stdc++.h>
using namespace std;

int convertToDecimal(string n) {
    int len = n.length();
    int p2 = 1;   // 2^0
    int num = 0;

    for (int i = len - 1; i >= 0; i--) {
        if (n[i] == '1') {
            num = num + p2;
        }
        p2 = p2 * 2;
    }

    return num;
}