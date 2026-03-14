#include <bits/stdc++.h>
using namespace std;

// Function to explain std::map
void explainMap() {
    map<int, int> mpp; // note: map store unique key in sorted order .

    // Inserting values into the map
    mpp[1] = 2;            // key = 1, value = 2
    mpp.emplace(3, 1);     // key = 3, value = 1
    mpp.insert({2, 4});    // key = 2, value = 4    // key = pair (2,3), value = 10 (⚠ invalid for map<int,int>)

    // Printing all key-value pairs
    for (auto it : mpp) {
        cout << it.first << " " << it.second << endl;
    }
    /*
       Output (ordered by key):
       1 2
       2 4
       3 1
       // note: {2,3} = 10 is invalid here since map<int,int> only allows int keys
    */

    // Accessing values
    cout << mpp[1] << endl;  // 2
    cout << mpp[5] << endl;  // 0 (creates key=5 with default value 0)

    // Using find()
    auto it = mpp.find(3);
    if (it != mpp.end())
        cout << it->second << endl; // 1

    auto it2 = mpp.find(5);
    if (it2 == mpp.end())
        cout << "Key 5 not found" << endl;

    // Lower bound and upper bound
    auto lb = mpp.lower_bound(2);
    cout << lb->first << " " << lb->second << endl;  // 2 4

    auto ub = mpp.upper_bound(3);
    if (ub != mpp.end())
        cout << ub->first << " " << ub->second << endl;
    else
        cout << "No upper bound for 3" << endl;

    /*
       Expected sample outputs:
       2
       0
       1
       Key 5 not found
       2 4
       (depends on content, likely "5 0" or "No upper bound")
    */
}

// Function to explain std::multimap
void explainMultimap() {
    multimap<int, int> mpp;
    // Similar to map, but allows duplicate keys
    mpp.insert({1, 100});
    mpp.insert({1, 200});
    mpp.insert({2, 300});

    for (auto it : mpp) {
        cout << it.first << " " << it.second << endl;
    }
    /*
       Output:
       1 100
       1 200
       2 300
    */
}

// Function to explain std::unordered_map
void explainUnorderedMap() { // it will have unique key but not sorted ... TC is O(1) but in worst case is O(n) which is very rare 
    unordered_map<int, int> mpp;
    mpp[1] = 10;
    mpp[2] = 20;
    mpp[3] = 30;

    for (auto it : mpp) {
        cout << it.first << " " << it.second << endl;
    }
    /*
       Output (unordered, order may vary):
       1 10
       2 20
       3 30
    */
}

// Custom comparator example
bool comp(pair<int, int> p1, pair<int, int> p2) {
    if (p1.second < p2.second) return true;
    else if (p1.second == p2.second && p1.first > p2.first) return true;
    return false;
}

int main() {
    explainMap();
    explainMultimap();
    explainUnorderedMap();
    return 0;
}
