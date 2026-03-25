#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* back;

    // Constructor with 3 params
    Node(int data1, Node* next1, Node* back1) {
        data = data1;
        next = next1;
        back = back1;
    }

    // Constructor with 1 param
    Node(int data1) {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

// Convert array to DLL
Node* convertArrtoDLL(vector<int> &arr) {
    if (arr.size() == 0) return nullptr;

    Node* head = new Node(arr[0]);
    Node* prev = head;

    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i], nullptr, prev);

        prev->next = temp;   // forward link
        // temp->back already set via constructor

        prev = temp;
    }
    return head;
}

void print(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};

    Node* head = convertArrtoDLL(arr);
    print(head);

    return 0;
}