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

