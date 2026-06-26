// stack implementation using array 

class StackImp {
    int topIdx = -1;
    int st[10];

public:
    void push(int n) {
        if (topIdx == 9) return; // Stack Overflow
        topIdx++;
        st[topIdx] = n;
    }

    int top() {
        if (topIdx == -1) return -1;
        return st[topIdx];
    }

    void pop() {
        if (topIdx == -1) return; // Stack Underflow
        topIdx--;
    }

    int size() {
        return topIdx + 1;
    }
};

// all the operation will be done is tc = O(1) and for space complexity will be there 


// queue implementation using array

#include <iostream>
using namespace std;

class QueueImp {
    int start = -1;
    int end = -1;
    int currSize = 0;
    int q[10];

public:
    void push(int x) {
        if (currSize == 10) {
            cout << "Queue Overflow\n";
            return;
        }

        if (currSize == 0) {
            start = 0;
            end = 0;
        }
        else {
            end = (end + 1) % 10;
        }

        q[end] = x;
        currSize++;
    }

    int pop() {
    if (currSize == 0) {
        cout << "Queue Underflow\n";
        return -1;
    }

    int el = q[start];

    if (currSize == 1) {
        start = end = -1;
    }
    else {
        start = (start + 1) % 10;   // or % size
    }

    currSize--;

    return el;
    }


    int top() {
        if (currSize == 0)
            return -1;

        return q[start];
    }

    int size() {
        return currSize;
    }

    bool empty() {
        return currSize == 0;
    }
};

int main() {
    QueueImp q;

    q.push(3);
    q.push(2);
    q.push(4);

    cout << q.top() << endl; 
    cout << q.pop() << endl;  

    cout << q.top() << endl;

    q.push(7);
    q.push(8);

    while (!q.empty()) {
        cout << q.top() << " ";
        q.pop();
    }

    return 0;
}




// in case of array implementation of stack and queue the time complexity for all the operations will be O(1) and space complexity will be O(n) where n is the size of the array.

// for dynamic size implementation of stack and queue we can use linked list or vector in c++ which will give us dynamic size and also the time complexity for all the operations will be O(1) and space complexity will be O(n) where n is the number of elements in the stack or queue.

// stack implementation using linked list

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class StackImp {
    Node* head = nullptr;
    int currSize = 0;

public:
    // Push
    void push(int x) {
        Node* node = new Node(x);

        node->next = head;
        head = node;

        currSize++;
    }

    // Pop
    int pop() {
        if (head == nullptr) {
            cout << "Stack Underflow\n";
            return -1;
        }

        int number = head->data;

        Node* temp = head;
        head = head->next;
        delete temp;

        currSize--;

        return number;
    }

    // Peek / Top
    int top() {
        if (head == nullptr) {
            cout << "Stack is Empty\n";
            return -1;
        }

        return head->data;
    }

    // Empty
    bool isEmpty() {
        return currSize == 0;
    }

    // Size
    int size() {
        return currSize;
    }
};

int main() {
    StackImp st;

    st.push(4);
    st.push(8);
    st.push(15);

    cout << st.top() << endl;      // 15

    cout << st.pop() << endl;      // 15

    cout << st.top() << endl;      // 8

    cout << st.size() << endl;     // 2

    cout << st.isEmpty() << endl;  // 0

    return 0;
}

// time and space complexity for stack implementation using linked list will be O(1) for all the operations and O(n) for space complexity where n is the number of elements in the stack.

// queue implementation using linked list

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class QueueImp {
    Node* head = nullptr;
    Node* tail = nullptr;
    int currSize = 0;

public:
    // Push (Enqueue)
    void push(int x) {
        Node* node = new Node(x);

        if (head == nullptr) {
            head = tail = node;
        }
        else {
            tail->next = node;
            tail = node;
        }

        currSize++;
    }

    // Pop (Dequeue)
    int pop() {
        if (head == nullptr) {
            cout << "Queue Underflow\n";
            return -1;
        }

        int number = head->data;

        Node* temp = head;
        head = head->next;
        delete temp;

        currSize--;

        if (head == nullptr) {
            tail = nullptr;
        }

        return number;
    }

    // Front
    int front() {
        if (head == nullptr) {
            cout << "Queue is Empty\n";
            return -1;
        }

        return head->data;
    }

    // Back
    int back() {
        if (tail == nullptr) {
            cout << "Queue is Empty\n";
            return -1;
        }

        return tail->data;
    }

    // Empty
    bool isEmpty() {
        return currSize == 0;
    }

    // Size
    int size() {
        return currSize;
    }
};

int main() {
    QueueImp q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << q.front() << endl;   // 10
    cout << q.back() << endl;    // 30

    cout << q.pop() << endl;     // 10

    cout << q.front() << endl;   // 20
    cout << q.back() << endl;    // 30

    cout << q.size() << endl;    // 2

    cout << q.isEmpty() << endl; // 0

    return 0;
}

// time and space complexity for queue implementation using linked list will be O(1) for all the operations and O(n) for space complexity where n is the number of elements in the queue.


// stack using queue

class MyStack {
public:
      queue<int> q1;
      queue<int> q2;
      
    MyStack() {
        
    }
    
    void push(int x) {
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();

        }
        q1.push(x);

        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
    }
    
    int pop() {
        int ans = q1.front();
        q1.pop();
        return ans;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};

// time complexity for push operation is O(n) and for pop, top and empty operation is O(1). Space complexity is O(n) where n is the number of elements in the stack.

// queue using stack

class MyQueue {
public:
      stack<int> s1;
      stack<int>s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);

        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        int ans = s1.top();
        s1.pop();
        return ans;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};

// time complexity for push operation is O(n) and for pop, peek and empty operation is O(1). Space complexity is O(n) where n is the number of elements in the queue.

// we can optimize push operation to O(1) and pop operation to O(n) by using two stacks. In this case, we will push the elements into the first stack and when we want to pop an element, we will transfer all the elements from the first stack to the second stack and then pop the top element from the second stack. This way, we can achieve O(1) time complexity for push operation and O(n) time complexity for pop operation.

class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;

    MyQueue() {
    }

    void push(int x) {
        s1.push(x);
    }

    int pop() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        int ans = s2.top();
        s2.pop();
        return ans;
    }

    int peek() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        return s2.top();
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }
};

// so we basically do tradeoff between push and pop operation. In the first implementation, we optimized pop operation to O(1) and in the second implementation, we optimized push operation to O(1). Depending on the use case, we can choose either of the implementations.