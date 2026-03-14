// stack<int> st;

// st.push(1);   // {1}
// st.push(2);   // {2, 1}
// st.push(3);   // {3, 2, 1}
// st.push(3);   // {3, 3, 2, 1}
// st.emplace(5); // {5, 3, 3, 2, 1}
// cout << st.top();   // prints 5
// st.pop();   // removes 5
// cout << st.top();   // prints 3
// cout << st.size();   // 4
// cout << st.empty();  // 0 (false)


/*❌ Why st[2] is INVALID (important)
st[2];   // ❌ NOT ALLOWED


Because:

stack is a container adapter

It does NOT expose random access

Internally it may use deque or vector, but you are not allowed to touch them

If you need indexing → use vector or deque*/


// to access 
// while (!st.empty()) {
//     cout << st.top() << " ";
//     st.pop();
// }
