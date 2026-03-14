#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <set>
using namespace std;

// ===========================================
// VECTOR OPERATIONS
// ===========================================
void explainVector() {
    vector<int> v = {10, 20, 30, 40, 50};
    
    // Vector iterator declarations
    vector<int>::iterator it = v.begin();
    
    it++;
    cout << *(it) << " ";  // Use * to dereference iterator
    
    it = it + 2;  // Can add/subtract numbers to iterators
    cout << *(it) << " ";
    
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
    
    // Swap operations
    vector<int> v1 = {10, 20};
    vector<int> v3 = {30, 40};
    v1.swap(v3); // Efficiently swap two vectors
    
    v2.clear(); // Remove all elements
    cout << v2.empty(); // Returns true if empty
}

// ===========================================
// LIST OPERATIONS
// ===========================================
void explainList() {
    list<int> ls;
    
    ls.push_back(2); // {2}
    ls.emplace_back(4); // {2, 4}
    
    ls.push_front(5); // {5, 2, 4}
    ls.emplace_front(); // {2, 4}
    
    // rest functions same as vector
    // begin, end, rbegin, rend, clear, insert, size, swap
}

// ===========================================
// DEQUE OPERATIONS  
// ===========================================
void explainDeque() {
    deque<int> dq;
    dq.push_back(1); // {1}
    dq.emplace_back(2); // {1, 2}
    dq.push_front(4); // {4, 1, 2}
    dq.emplace_front(3); // {3, 4, 1, 2}
    
    dq.pop_back(); // {3, 4, 1}
    dq.pop_front(); // {4, 1}
    
    dq.back();
    dq.front();
    
    // rest functions same as vector
    // begin, end, rbegin, rend, clear, insert, size, swap
}

// ===========================================
// STACK OPERATIONS
// ===========================================
void explainStack() {
    stack<int> st;
    st.push(1);
    st.push(2); // {2, 1}
    st.push(3); // {3, 2, 1}
    st.push(3); // {3, 3, 2, 1}
    st.emplace(5); // {5, 3, 3, 2, 1}
    
    cout << st.top(); // prints 5 "=> st[2] is invalid"
    
    st.pop(); // st looks like {3, 3, 2, 1}
    
    cout << st.top(); // 3
    
    cout << st.size(); // 4
    
    cout << st.empty();
    
    stack<int> st1, st2;
    st1.swap(st2);
}

// ===========================================
// QUEUE OPERATIONS
// ===========================================
void explainQueue() {
    queue<int> q;
    q.push(1); // {1}
    q.push(2); // {1, 2}
    q.emplace(4); // {1, 2, 4}
    
    q.back() += 5;
    
    cout << q.back(); // prints 9
    
    // Q is {1, 2, 9}
    cout << q.front(); // prints 1
    
    q.pop(); // {2, 9}
    cout << q.front(); // prints 2
    
    // size swap empty same as stack
}

// ===========================================
// PRIORITY QUEUE OPERATIONS
// ===========================================
void explainPQ() {
    priority_queue<int> pq;
    pq.push(5); // {5}
    pq.push(2); // {5, 2}
    pq.push(8); // {8, 5, 2}
    pq.emplace(10); // {10, 8, 5, 2}
    
    cout << pq.top(); // prints 10
    
    pq.pop(); // {8, 5, 2}
    cout << pq.top(); // prints 8
    
    // size swap empty function same as others
    
    // Minimum Heap
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(5); // {5}
    pq.push(2); // {2, 5}
    pq.push(8); // {2, 5, 8}
    pq.emplace(10); // {2, 5, 8, 10}
    
    cout << pq.top(); // prints 2
}

// ===========================================
// SET OPERATIONS
// ===========================================
void explainSet() {
    set<int> st;
    st.insert(1); // {1}
    st.emplace(2); // {1, 2}
    st.insert(2); // {1, 2}
    st.insert(4); // {1, 2, 4}
    st.insert(3); // {1, 2, 3, 4}
    
    // Functionality of insert in vector
    // can be used also, that only increases
    // the efficiency
    
    // begin(), end(), rbegin(), rend(), size(),
    // empty() and swap() are same as those of above
    
    auto it = st.find(3);
    
    auto it = st.find(6);
    
    st.erase(5); // erases 5 // takes logarithmic time
    
    int cnt = st.count(1);
    
    auto it = st.find(3);
    st.erase(it); // it takes constant time
    
    // {1, 2, 3, 4, 5}
    auto it1 = st.find(2);
    auto it2 = st.find(4);
    st.erase(it1, it2); // after erase {1, 4, 5} [first, last)
    
    // lower_bound() and upper_bound() function works in the same way
    // as in vector it does.
    
    // This is the syntax
    auto it = st.lower_bound(2);
    
    auto it = st.upper_bound(3);
}

// ===========================================
// MULTISET OPERATIONS
// ===========================================
void explainMultiSet() {
    // Everything is same as set
    // only stores duplicate elements also
    
    multiset<int> ms;
    ms.insert(1); // {1}
    ms.insert(1); // {1, 1}
    ms.insert(1); // {1, 1, 1}
    
    ms.erase(1); // all 1's erased
    
    int cnt = ms.count(1);
    
    // only a single one erased
    ms.erase(ms.find(1));
    
    // To erase range, use different approach
    auto it1 = ms.find(1);
    auto it2 = ms.find(1);
    advance(it2, 2); // Move iterator 2 positions forward
    ms.erase(it1, it2);
    
    // rest all functions same as set
}

// ===========================================
// UNORDERED SET
// ===========================================
void explainUSet() {
    // unordered_set<int> st;
    // lower_bound and upper_bound function
    // does not work, rest all functions are same
    // as above, it does not stores in any
    // particular order it has a better complexity
    // than set in most cases, except some when collision happens
}

int main() {
    explainVector();
    explainList();
    explainDeque();
    explainStack();
    explainQueue();
    explainPQ();
    explainSet();
    explainMultiSet();
    explainUSet();
    
    return 0;
}