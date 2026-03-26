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



// delete head of DLL

Node* deleteHead(Node* head) {
    if(head == NULL) return NULL;

    if(head->next == NULL){
        delete head;
        return NULL;
    }

    Node* prev = head;
    head = head->next;

    head->back = nullptr;
    prev->next = nullptr;

    delete prev;

    return head;
}


/// delete last node 

Node* deleteTail(Node* head) {
    if(head == NULL) return NULL;

    // Single node case
    if(head->next == NULL){
        delete head;
        return NULL;
    }

    Node* tail = head;

    while(tail->next != NULL){
        tail = tail->next;
    }

    Node* newTail = tail->back;

    newTail->next = nullptr;
    tail->back = nullptr;

    delete tail;

    return head;
}

// delete kth element

Node* removeKthElement(Node* head, int k) {
    if(head == NULL) return NULL;
    if(k <= 0) return head;

    int cnt = 0;
    Node* kNode = head;

    while(kNode != NULL) {
        cnt++;
        if(cnt == k) break;
        kNode = kNode->next;
    }

    if(kNode == NULL) return head;

    Node* prev = kNode->back;
    Node* front = kNode->next;

    // Only one node
    if(prev == NULL && front == NULL) {
        delete kNode;
        return NULL;
    }
    // Head
    else if(prev == NULL) {
        return deleteHead(head);
    }
    // Tail
    else if(front == NULL) {
        return deleteTail(head);
    }

    // Middle node
    prev->next = front;
    front->back = prev;

    kNode->next = nullptr;
    kNode->back = nullptr;

    delete kNode;

    return head;
}


// delete a given node note that that node will never be the head of DLL

void deletenode(Node* temp){

    if (temp == NULL) return;

    Node* prev = temp->back;
    Node* front = temp->next;

    // node given is tail 
    if(front==NULL){
        prev-> next = nullptr;
        temp->back = nullptr;
        delete temp;
        return;
    }
    prev->next = front;
    front->back = prev;

    temp->next = temp->back = nullptr;
    delete temp;
    return;
}


//insertion before head 

Node* insertBeforeHead(Node* head, int val) {
    if(head == NULL){
        return new Node(val, nullptr, nullptr);
    }

    Node* newHead = new Node(val, head, nullptr);
    head->back = newHead;

    return newHead;
}

//insertion before tail

Node* insertBeforeTail(Node* head, int val) {
    if(head == NULL){
        return new Node(val, nullptr, nullptr);
    }

    if(head->next == NULL){
        return insertBeforeHead(head, val);
    }

    Node* tail = head;

    while(tail->next != NULL){
        tail = tail->next;
    }

    Node* prev = tail->back;
    Node* newNode = new Node(val, tail, prev);

    prev->next = newNode;
    tail->back = newNode;

    return head;
}


//insertion before kth element 


Node* insertBeforeKthElement(Node* head, int k, int val) {
    if(k <= 0) return head;

    if(head == NULL){
        if(k == 1) return new Node(val, nullptr, nullptr);
        return head;
    }

    if(k == 1){
        return insertBeforeHead(head, val);
    }

    Node* temp = head;
    int cnt = 0;

    while(temp != NULL){
        cnt++;
        if(cnt == k) break;
        temp = temp->next;
    }

    if(temp == NULL) return head;

    Node* prev = temp->back;
    Node* newNode = new Node(val, temp, prev);

    if(prev != NULL) prev->next = newNode;
    temp->back = newNode;

    return head;
}

//insert  before node and note that this node will never be head

void insertBeforeNode(Node* node, int val) {
    Node* prev = node->back;
    Node* newNode = new Node(val, node, prev);
    prev->next = newNode;
    node->back = newNode;
}

// insert after head 


Node* insertAfterHead(Node* head, int val) {
    if(head == NULL){
        return new Node(val, nullptr, nullptr);
    }

    Node* front = head->next;
    Node* newNode = new Node(val, front, head);

    head->next = newNode;

    if(front != NULL){
        front->back = newNode;
    }

    return head;
}

// insert after tail 


// insert at the end of DLL

Node* insertAtTail(Node* head, int k) {
    if (head == NULL) {
        return new Node(k);
    }

    Node* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }

    Node* newNode = new Node(k, nullptr, tail);
    tail->next = newNode;

    return head;
}


// insert after Kth element 


Node* insertAfterKthElement(Node* head, int k, int val) {
    if(k <= 0) return head;

    if(head == NULL){
        if(k == 1) return new Node(val, nullptr, nullptr);
        return head;
    }

    Node* temp = head;
    int cnt = 0;

    while(temp != NULL){
        cnt++;
        if(cnt == k) break;
        temp = temp->next;
    }

    if(temp == NULL) return head;

    Node* front = temp->next;
    Node* newNode = new Node(val, front, temp);

    temp->next = newNode;

    if(front != NULL){
        front->back = newNode;
    }

    return head;
}

// insert after given node note that node will never be tail

void insertAfterNode(Node* node, int val) {
    Node* front = node->next;
    Node* newNode = new Node(val, front, node);

    node->next = newNode;
    front->back = newNode;
}