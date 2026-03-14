// case 1 

#include <bits/stdc++.h>
using namespace std;

long long nCr(int n, int r) {
    long long res = 1;
    for (int i = 0; i < r; i++) {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}

int main() {
    int rows = 10;

    for (int n = 0; n < rows; n++) {
        // print spaces for triangle shape
        for (int s = 0; s < rows - n; s++)
            cout << " ";

        for (int r = 0; r <= n; r++) {
            cout << nCr(n, r) << " ";
        }
        cout << endl;
    }
}


// case 2 :
// brute force approach 

#include <bits/stdc++.h>
using namespace std;

long long fact(int x) {
    long long f = 1;
    for (int i = 1; i <= x; i++)
        f *= i;
    return f;
}

long long nCr(int n, int r) {
    long long num = fact(n);
    long long den = fact(r) * fact(n - r);
    return num / den;
}

// Return instead of printing
vector<long long> getNthRow(int n) {
    vector<long long> row;
    for (int c = 1; c <= n; c++) {
        row.push_back(nCr(n - 1, c - 1));
    }
    return row;
}

int main() {
    int n;
    cin >> n;

    vector<long long> row = getNthRow(n);

    // If we  WANT to print later, you can:
    for (long long x : row)
        cout << x << " ";
}


// case 2 optimal approach 

#include <bits/stdc++.h>
using namespace std;

vector<long long> getNthRow_Optimal(int n) {
    vector<long long> row;
    long long ans = 1;
    row.push_back(ans); // C(n,0) = 1

    for (int i = 1; i < n; i++) {
        ans = ans * (n - i);
        ans = ans / i;
        row.push_back(ans);
    }

    return row;
}

int main() {
    int n;
    cin >> n;
    
    vector<long long> result = getNthRow_Optimal(n);

    for (long long x : result)
        cout << x << " ";
}


//case 3 : brute 

#include <bits/stdc++.h>
using namespace std;

long long fact(int x) {
    long long f = 1;
    for (int i = 1; i <= x; i++)
        f *= i;
    return f;
}

long long nCr(int n, int r) {
    long long num = fact(n);
    long long den = fact(r) * fact(n - r);
    return num / den;
}

vector<vector<long long>> pascalBrute(int n) {
    vector<vector<long long>> ans;

    for (int row = 1; row <= n; row++) {
        vector<long long> temp;

        for (int col = 1; col <= row; col++) {
            temp.push_back(nCr(row - 1, col - 1));
        }

        ans.push_back(temp);
    }

    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<vector<long long>> tri = pascalBrute(n);

    for (auto &row: tri) {
        for (long long x: row)
            cout << x << " ";
        cout << endl;
    }
}


// case 3 optimal 


#include <vector>
#include <iostream>
using namespace std;

vector<int> generateRow(int row) {
    long long ans = 1;
    vector<int> ansRow;
    ansRow.push_back(1);
    for (int col = 1; col < row; col++) {
        ans = ans * (row - col);
        ans = ans / col;
        ansRow.push_back(ans);
    }
    return ansRow;
}

vector<vector<int>> pascalTriangle(int N) {
    vector<vector<int>> ans;
    for (int i = 1; i <= N; i++) {
        ans.push_back(generateRow(i));
    }
    return ans;
}

int main() {
    int N = 5;
    vector<vector<int>> result = pascalTriangle(N);
    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}