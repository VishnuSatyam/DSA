#include <bits/stdc++.h>
using namespace std;

void explainVectors() {
    // Simple vector of integers
    vector<int> v;
    v.push_back(1);       // Inserts 1 at the end
    v.emplace_back(2);    // Same as push_back for simple types, but can be faster

    // Vector of pairs
    vector<pair<int, int>> vec;
    vec.push_back({1, 2});      // Must pass a pair object
    vec.emplace_back(1, 2);     // Directly constructs the pair (faster, cleaner)

    // Initializing a vector with a fixed size and value
    vector<int> v1(5, 100);     // {100, 100, 100, 100, 100}

    // Initializing with default values (0 for int)
    vector<int> v2(5);          // {0, 0, 0, 0, 0}

    // Copying a vector
    vector<int> v3(v1);         // Copy of v1 → {100, 100, 100, 100, 100}
}




// Now to access the elements we can use different ways which are:::
// using indxing like array::

int main() {
    explainVectors();

    vector<int> v1 = {10, 20, 30, 40};
    
    // Access using indexing
    for (int i = 0; i < v1.size(); i++) {
        cout << v1[i] << " ";
    }
    cout << "\n";

    return 0;
}
