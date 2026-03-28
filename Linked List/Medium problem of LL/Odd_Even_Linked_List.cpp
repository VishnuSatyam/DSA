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

// brute force approach 

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL) return head;

        vector<int> arr;
        ListNode* temp = head;

        // Step 1: odd positions
        while (temp != NULL) {
            arr.push_back(temp->val);
            if (temp->next == NULL) break;
            temp = temp->next->next;
        }

        // Step 2: even positions
        temp = head->next;
        while (temp != NULL) {
            arr.push_back(temp->val);
            if (temp->next == NULL) break;
            temp = temp->next->next;
        }

        // Step 3: rewrite list
        temp = head;
        int i = 0;
        while (temp != NULL) {
            temp->val = arr[i++];
            temp = temp->next;
        }

        return head;
    }
};


// optimal approach 

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = head->next;

        while (even != NULL && even->next != NULL) {
            odd->next = odd->next->next;
            even->next = even->next->next;

            odd = odd->next;
            even = even->next;
        }

        odd->next = evenHead;
        return head;
    }
};