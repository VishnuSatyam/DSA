#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Initialize vector for demonstration
    vector<int> v = {10, 20, 30, 40, 50};
    
    // Vector iterator declarations
    vector<int>::iterator it = v.begin();
    
    it++;
    cout << *(it) << " ";  // Use * to dereference iterator
    
    it = it + 2;  // Can add/subtract numbers to iterators
    cout << *(it) << " ";
    
    // Different iterator types (separate declarations)
    vector<int>::iterator it1 = v.end();     // Points AFTER last element
    vector<int>::reverse_iterator it2 = v.rend();    // Reverse iterators
    vector<int>::reverse_iterator it3 = v.rbegin();
    
    // Element access
    cout << v[0] << " " << v.at(0);  // at() is safer (bounds checking)
    cout << v.back() << " ";         // Last element
    
    // Three ways to iterate
    for (vector<int>::iterator iter = v.begin(); iter != v.end(); iter++) {
        cout << *(iter) << " ";  // Traditional iterator
    }
    
    for (auto iter = v.begin(); iter != v.end(); iter++) {
        cout << *(iter) << " ";  // Auto deduces type
    }
    
    for (auto element : v) {
        cout << element << " ";  // Range-based: 'element' is value, not iterator
    }
    
    // Insert operations
    vector<int> v2(2, 100); // {100, 100} - creates 2 elements with value 100
    v2.insert(v2.begin(), 300); // Insert at position
    v2.insert(v2.begin() + 1, 2, 10); // Insert 2 copies of value 10
    
    vector<int> copy(2, 50);
    v2.insert(v2.begin(), copy.begin(), copy.end()); // Insert range
    
    cout << v2.size(); // Number of elements
    
    v2.pop_back(); // Remove last element
    
    // Erase operations
    v2.erase(v2.begin() + 1); // Erase single element
    v2.erase(v2.begin() + 2, v2.begin() + 4); // Erase range [start, end) - end excluded
    
    // Swap operations (need two vectors)
    vector<int> v1 = {10, 20};
    vector<int> v3 = {30, 40};
    v1.swap(v3); // Efficiently swap two vectors
    
    v2.clear(); // Remove all elements
    cout << v2.empty(); // Returns true if empty
    
    return 0;
}