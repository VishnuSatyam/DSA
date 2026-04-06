#include <bits/stdc++.h>
using namespace std;

void insertSorted(stack<int>& s, int element) {
    // Base case
    if (s.empty() || s.top() <= element) {
        s.push(element);
        return;
    }

    int top = s.top();
    s.pop();

    // Recursive call
    insertSorted(s, element);

    // Put back the removed element
    s.push(top);
}

void sortStack(stack<int>& s) {
    // Base case
    if (s.empty() || s.size() == 1) {
        return;
    }

    int top = s.top();
    s.pop();

    // Recursive call to sort remaining stack
    sortStack(s);

    // Insert the popped element in sorted order
    insertSorted(s, top);
}