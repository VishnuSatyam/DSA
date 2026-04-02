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
    ListNode* getKthNode(ListNode* curr, int k) {
        while (curr != NULL && k > 1) {
            curr = curr->next;
            k--;
        }
        return curr;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr != NULL) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || k == 1) return head;

        ListNode* temp = head;
        ListNode* groupPrev = NULL; 

        while (temp != NULL) {
            ListNode* kthNode = getKthNode(temp, k);

            if (kthNode == NULL) {
                if (groupPrev) groupPrev->next = temp;
                break;
            }

            ListNode* nextNode = kthNode->next;
            kthNode->next = NULL;

            ListNode* newHead = reverseList(temp);

            if (temp == head) {
                head = newHead;
            } else {
                groupPrev->next = newHead;
            }

            groupPrev = temp;   // now tail of reversed group
            temp = nextNode;
        }

        return head;
    }
}; 