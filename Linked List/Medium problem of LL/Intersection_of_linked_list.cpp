#include<bits/stdc++.h>
using namespace std;
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        map<ListNode* , int>mpp;
        ListNode* temp1 = headA;
        while(temp1 != NULL){
            mpp[temp1] = 1;
            temp1 = temp1->next;
        }
        ListNode* temp2 = headB;
        while(temp2 != NULL){
            if(mpp.find(temp2) != mpp.end()){
                return temp2;
            }
            temp2 = temp2->next;
        }
        return NULL;
    }
};

// better approach 

class Solution {
public:
    ListNode* intersection(ListNode* temp1 , ListNode* temp2 , int diff){
        while(diff){
            diff--;
            temp2 = temp2->next;
        }
        while(temp1 && temp2 && temp1 != temp2){
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return (temp1 == temp2) ? temp1 : NULL; // we can return either 
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1 = headA;
        int n1 = 0;
        while(temp1 != NULL){
            n1++;
            temp1 = temp1->next;
        }
        ListNode* temp2 = headB;
        int n2 = 0;
        while(temp2 != NULL){
            n2++;
            temp2 = temp2->next;
        }
        if(n1<n2){
            return intersection(headA , headB , n2-n1);
        }
        else{
            return intersection(headB , headA , n1-n2);
        }
    }
};

// most optimal approach using two pointers 

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;

        while (temp1 != temp2) {
            if (temp1 == NULL) {
                temp1 = headB;
            } else {
                temp1 = temp1->next;
            }

            if (temp2 == NULL) {
                temp2 = headA;
            } else {
                temp2 = temp2->next;
            }
        }

        return temp1; // or temp2 (both are same here)
    }
};