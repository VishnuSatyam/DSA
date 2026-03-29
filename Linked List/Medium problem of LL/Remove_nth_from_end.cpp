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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode* temp = head;

        // Step 1: count length
        while(temp != NULL){
            count++;
            temp = temp->next;
        }

        // Step 2: if head needs to be deleted
        if(count == n){
            ListNode* newhead = head->next;
            delete head;
            return newhead;
        }

        // Step 3: go to (count - n)th node
        int result = count - n;
        temp = head;

        while(result > 1){
            temp = temp->next;
            result--;
        }

        // Step 4: delete node
        ListNode* delNode = temp->next;
        temp->next = temp->next->next;
        delete delNode;

        return head;
    }
};


// optimal approach 

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;

        // move fast n steps
        for(int i = 0; i < n; i++){
            fast = fast->next;
        }

        // 🔥 edge case: delete head
        if(fast == NULL){
            ListNode* newhead = head->next;
            delete head;
            return newhead;
        }

        ListNode* slow = head;

        // move both pointers
        while(fast->next != NULL){
            slow = slow->next;
            fast = fast->next;
        }

        // delete node
        ListNode* delNode = slow->next;
        slow->next = slow->next->next;
        delete delNode;

        return head;
    }
};


// using dummy node 

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* p = dummy;
        ListNode* q = dummy;

        for(int i = 0; i <= n; i++){
            p = p->next;
        }

        while(p != NULL){
            p = p->next;
            q = q->next;
        }

        // delete node 
        ListNode* delNode = q->next;
        q->next = q->next->next;
        delete delNode;

        ListNode* newHead = dummy->next;
        delete dummy;  // optional but clean

        return newHead;
    }
};