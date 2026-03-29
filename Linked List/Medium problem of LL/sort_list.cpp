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
    ListNode* sortList(ListNode* head) {
        vector<int>arr;
        ListNode* temp = head;
        while(temp != NULL){
            arr.push_back(temp->val);
            temp = temp->next;
        }
        sort(arr.begin() , arr.end());
        temp = head;
        int i =0;
        while(temp !=  NULL){
            temp->val = arr[i];
            i++;
            temp = temp->next;
        }
        return head; 
    }
};


// optimal approach using merge sort

class Solution {
public:
    Node* findMiddle(Node* head) {
        Node* slow = head;
        Node* fast = head->next; // this is so that we get first middle in case of even nodes 

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    Node* mergeTwoLists(Node* list1, Node* list2) {
        Node* dummyNode = new Node(-1);
        Node* temp = dummyNode;

        while(list1 && list2){
            if(list1->data < list2->data){
                temp->next = list1;
                list1 = list1->next;
            } else {
                temp->next = list2
                list2 = list2->next;
            }
            temp = temp->next;
        }

        if(list1) temp->next = list1;
        else temp->next = list2;

        return dummyNode->next;
    }

    Node* sortLL(Node* head) {
        if(head == NULL || head->next == NULL) return head;

        Node* middle = findMiddle(head);
        Node* right = middle->next;
        middle->next = NULL;

        Node* left = sortLL(head);
        right = sortLL(right);

        return mergeTwoLists(left, right);
    }
};