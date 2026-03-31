#include<bits/stdc++.h>
using namespace std;

/**
 * Definition of doubly linked list:
 * class Node {
 * public:
 *      int data;
 *      Node *prev;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next, Node *prev) {
 *          this -> data = data;
 *          this -> prev = prev;
 *          this -> next = next;
 *      }
 * };
 *
 *************************************************************************/


// brute force approach 
vector<pair<int, int>> findPairs(Node* head, int k){

    Node* temp1 = head;
    vector<pair<int,int>> arr;

    while(temp1 != NULL){
        Node* temp2 = temp1->next;

        while(temp2 != NULL){
            int sum = temp1->data + temp2->data;

            if(sum == k){
                arr.push_back({temp1->data, temp2->data});
            }
            else if(sum > k){
                break;
            }

            temp2 = temp2->next;
        }

        temp1 = temp1->next;
    }

    return arr;
}

// optimal approach 

vector<pair<int, int>> findPairs(Node* head, int k){
    if(head == NULL) return {};

    Node* left = head;

    // find last node
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    Node* right = temp;

    vector<pair<int,int>> arr;

    while(left != NULL && right != NULL && left != right && left->prev != right){
        int sum = left->data + right->data;

        if(sum == k){
            arr.push_back({left->data, right->data});
            left = left->next;
            right = right->prev;
        }
        else if(sum < k){
            left = left->next;
        }
        else{
            right = right->prev;
        }
    }

    return arr;
}