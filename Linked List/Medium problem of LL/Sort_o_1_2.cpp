#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node* next) : data(x), next(next) {}
};
// brute force approach 
class Solution {
public:
    Node* count012(Node* head) {
        Node* temp = head;
        int count0 = 0, count1 = 0, count2 = 0;

        // Count 0s, 1s, 2s
        while (temp != NULL) {
            if (temp->data == 0) count0++;
            else if (temp->data == 1) count1++;
            else count2++;
            temp = temp->next;
        }

        // Replace values
        temp = head;
        while (temp != NULL) {
            if (count0 > 0) {
                temp->data = 0;
                count0--;
            }
            else if (count1 > 0) {
                temp->data = 1;
                count1--;
            }
            else {
                temp->data = 2;
                count2--;
            }
            temp = temp->next; 
        }

        return head;
    }
};

// optimal approach 

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) : data(x), next(nullptr) {}
};

class Solution {
public:
    Node* sortList(Node* head) {
        if (!head || !head->next) return head;

        // Dummy heads
        Node* zeroHead = new Node(-1);
        Node* oneHead  = new Node(-1);
        Node* twoHead  = new Node(-1);

        // Tail pointers
        Node* zero = zeroHead;
        Node* one  = oneHead;
        Node* two  = twoHead;

        Node* temp = head;

        // Divide into 3 lists
        while (temp) {
            if (temp->data == 0) {
                zero->next = temp;
                zero = zero->next;
            } 
            else if (temp->data == 1) {
                one->next = temp;
                one = one->next;
            } 
            else {
                two->next = temp;
                two = two->next;
            }
            temp = temp->next;
        }

        // Connect lists
        zero->next = (oneHead->next) ? oneHead->next : twoHead->next;
        one->next  = twoHead->next;
        two->next  = NULL;

        // New head
        Node* newHead = zeroHead->next;

        // Delete dummy nodes
        delete zeroHead;
        delete oneHead;
        delete twoHead;

        return newHead;
    }
};