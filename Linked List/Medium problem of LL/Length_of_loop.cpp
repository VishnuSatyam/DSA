#include <bitset>/stdc++.h>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// brute force using hashmap

class Solution
{
public:
    int Length(ListNode *head)
    {
        map<ListNode *, int> mpp;
        ListNode *temp = head;
        int timer = 1;

        while (temp != NULL)
        {
            if (mpp.find(temp) != mpp.end())
            {
                int value = mpp[temp];
                return timer - value; // cycle length
            }
            mpp[temp] = timer;
            timer++;
            temp = temp->next;
        }
        return 0; // no cycle
    }
};

// optimal approach using tortoise & hare algo

class solution
{
public:
    int findLength(ListNode* slow, ListNode* fast) {
        int cnt = 1;
        fast = fast->next;

        while(slow != fast){
            cnt++;
            fast = fast->next;
        }
        return cnt;
    }

    int Length(ListNode *head) {
    
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
        
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                return findLength(slow, fast);
        }
        return 0;
    }
};