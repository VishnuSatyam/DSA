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
    ListNode* findNthNode(ListNode* head, int k) {
        while (head != NULL && k > 1) {
            head = head->next;
            k--;
        }
        return head;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 0) return head;

        ListNode* tail = head;
        int len = 1;

        while (tail->next != NULL) {
            tail = tail->next;
            len++;
        }

        k = k % len;
        if (k == 0) return head;

        tail->next = head;

        ListNode* newTail = findNthNode(head, len - k);

        ListNode* newHead = newTail->next;
        newTail->next = NULL;

        return newHead;
    }
};