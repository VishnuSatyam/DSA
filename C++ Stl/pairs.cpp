#include <iostream>
#include <utility> // for std::pair
using namespace std;

void explainPairs() {
    // Simple pair
    pair<int, int> p = {1, 2};
    cout << p.first << " " << p.second << endl; // Output: 1 2

    // Nested pair
    pair<int, pair<int, int>> p2 = {1, {2, 3}};
    cout << p2.first << " " << p2.second.first << " " << p2.second.second << endl; // Output: 1 2 3

    // Array of pairs
    pair<int, int> arr[] = {{1, 2}, {2, 3}, {3, 4}, {5, 1}};
    cout << arr[1].first << " " << arr[1].second << endl; // Output: 2 3
}

int main() {
    explainPairs();
    return 0;
}
