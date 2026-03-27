/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 // brute force approach 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        map <ListNode* , int> mpp;
        ListNode* temp;
        while(temp != NULL){
            if(mpp.find(temp) != mpp.end()){
                return true;
            }
            mpp[temp] = 1;
            temp = temp->next;
        }
        return false;
    }
};

// optimal approach using slow and fast pointer

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL && fast->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
            if(slow == fast) return true;
        }
        return false;
    }
};