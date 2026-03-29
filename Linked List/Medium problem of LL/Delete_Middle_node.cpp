#include<bits/stdc++.h>
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
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL || head->next == NULL) return NULL;

        int n = 0;
        ListNode* temp = head;

        // count length
        while(temp != NULL){
            n++;
            temp = temp->next;
        }

        int res = n / 2;

        temp = head;

        // move to node BEFORE middle
        while(res > 1){
            temp = temp->next;
            res--;
        }

        // delete middle
        ListNode* mid = temp->next;
        temp->next = temp->next->next;
        delete mid;

        return head;
    }
};

// optimal approach but not best 

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL || head->next == NULL) return NULL;

        ListNode* slow = head;
        ListNode* fast = head;

        // shift fast ahead
        fast = fast->next->next;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        // delete middle (slow->next)
        ListNode* delNode = slow->next;
        slow->next = slow->next->next;
        delete delNode;

        return head;
    }
};

// most optimal approach 

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL || head->next == NULL) return NULL;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        while(fast != NULL && fast->next != NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // slow is middle
        prev->next = slow->next;
        delete slow;

        return head;
    }
};