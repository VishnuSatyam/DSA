#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// brute force approach 
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* temp = head;
        int count = 0;
        while(temp != NULL){
            count++;
            temp = temp->next;
        }

        int midnode = (count/2)+1;
        temp = head;
        while(temp != NULL){
            midnode--;
            if(midnode==0) break;
            temp = temp->next;
        }
        return temp;
    }
};

// optimal approach using tortoise and hare algo 

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){ // if even node then first condition fails else sencond condition fails
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;

    }
} ;

