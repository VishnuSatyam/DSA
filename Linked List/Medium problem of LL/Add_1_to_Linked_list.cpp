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


// brute force approach
class Solution {
public:
    
    // Reverse linked list
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }

    ListNode* addOne(ListNode* head) {
        // Step 1: Reverse
        head = reverse(head);

        ListNode* temp = head;
        int carry = 1;

        // Step 2: Add carry
        while (temp && carry) {
            int sum = temp->val + carry;
            temp->val = sum % 10;
            carry = sum / 10;

            // Move forward
            if (temp->next == NULL && carry) {
                temp->next = new ListNode(carry);
                carry = 0;
                break;
            }

            temp = temp->next;
        }

        // Step 3: Reverse back
        head = reverse(head);

        return head;
    }
};

// optimal approach using recursion


class Solution {
public:

    int helper(ListNode* head) {
        // Base case: after the last node
        if (head == NULL) return 1;  // initial carry = 1

        int carry = helper(head->next);

        int sum = head->val + carry;
        head->val = sum % 10;

        return sum / 10; // pass carry back
    }

    ListNode* addOne(ListNode* head) {
        int carry = helper(head);

        // If carry still remains → add new node at front
        if (carry) {
            ListNode* newHead = new ListNode(carry);
            newHead->next = head;
            return newHead;
        }

        return head;
    }
};