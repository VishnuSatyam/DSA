// naive approach 

#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next,*prev;
    Node()
    {
        this->data = 0;
        next = NULL;
        prev= NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
        this->prev= NULL;
    }
    Node(int data, Node* next, Node *prev)
    {
        this->data = data;
        this->next = next;
        this->prev= prev;
    }
};

Node* reverse(Node* head){
    if(head == NULL) return head;

    stack<int> st;
    Node* temp = head;

    while(temp != NULL){
        st.push(temp->data);
        temp = temp->next;
    }

    temp = head;

    while(temp != NULL){
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }

    return head;
}

// optimal approach 

Node* reverseDLL(Node* head){
    if(head== NULL || head->next == NULL){
        return head;
    }
    Node* last = NULL;
    Node* curr = head;
    while(curr != NULL){
        last = curr->prev;
        curr->prev = curr->next;
        curr->next = last;

        curr = curr->prev;
    }
    if (last != NULL) {
        head = last->prev;
    }

    return head;  // this will be the new head
}