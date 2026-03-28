/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// brute force  using stack
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack <int> st;
        ListNode* temp = head;

        while(temp != NULL){
            st.push(temp->data);
            temp = temp->next;
        }
        temp = head;
        while(temp != NULL){
            if(temp->data != st.top()){
                return false;
            }
            temp = temp->next;
            st.pop();
        }
        return true;
    }
};

// optimal approach 


Node* reverseLinkedList(Node* head) {
    Node* prev = NULL;
    Node* curr = head;

    while (curr != NULL) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool isPalindrome(Node* head)
{
    if(head == NULL || head->next == NULL) return true;

    Node* slow = head;
    Node* fast = head;

    while(fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* newHead = reverseLinkedList(slow->next);

    Node* first = head;
    Node* second = newHead;

    while(second != NULL) {
        if(first->data != second->data) {
            reverseLinkedList(newHead); // restore
            return false;
        }
        first = first->next;
        second = second->next;
    }

    reverseLinkedList(newHead); // restore list
    return true;
}