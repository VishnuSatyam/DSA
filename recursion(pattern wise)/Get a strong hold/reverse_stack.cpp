#include<bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int>& s, int element) {
    if (s.empty()) {
        s.push(element);
        return;
    }

    int top = s.top();
    s.pop();

    insertAtBottom(s, element);

    s.push(top);
}

void reverseStack(stack<int>& s) {
    if (s.empty()) return;

    int top = s.top();
    s.pop();

    reverseStack(s);

    insertAtBottom(s, top);
}