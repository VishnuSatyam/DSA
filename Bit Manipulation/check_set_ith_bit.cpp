// we can first convert to binary and then check the ith bit is set or not but that will be a bit lengthy process so we can directly check the ith bit is set or not by using bit manipulation

bool isSet(int n, int i) {
    string bin = "";

    while (n > 0) {
        bin += char('0' + n % 2);
        n /= 2;
    }

    if (i >= bin.size()) return false;

    return bin[i] == '1';
}

// tc will be O(logn) and sc will be O(logn) as we are storing the binary representation of the number in a string.

// using bitwise operator

// Method 1 using right shift 

bool isSet(int n, int i) {
    return (n >> i) & 1;
}

// method 2 using left shift

bool isSet(int n, int i) {
    return (n & (1 << i)) != 0;
}

// tc and sc for both the above methods will be O(1) as we are using only constant time and space to check the ith bit is set or not.