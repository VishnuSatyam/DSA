// brute force 

int setBit(int n, int i) {
    int p = 1;

    for (int j = 0; j < i; j++) {
        p *= 2;
    }

    int x = n / p;

    if (x % 2 == 0) {
        n += p;
    }

    return n;
}

// using bitwise operator

int n = 10; // 1010
int i = 0;

n = n | (1 << i);

cout << n; // 11