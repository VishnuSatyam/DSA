#include<bitset>/stdc++.h>
using namespace std;

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


 // brute force using stack

 ListNode* reverse(ListNode* head){
    if(head == NULL) return head;

    stack<int> st;
    ListNode* temp = head;

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

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* first = head;

        while(first != NULL) {
            ListNode* next = first->next;  
            first->next = prev;            
            prev = first;                  
            first = next;                  
        }

        return prev;
    }
};