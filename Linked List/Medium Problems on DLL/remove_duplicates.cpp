#include<bits>/sttdc++.h>
using namespace std;
/**
 * Definition of doubly linked list:
 *
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
 *          this->data = data;
 *          this->prev = prev;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node* removeDuplicates(Node* head) {
    if (!head) return head;

    Node* temp = head;

    while (temp != NULL && temp->next != NULL) {
        if (temp->data == temp->next->data) {
            Node* duplicate = temp->next;

            // remove duplicate
            temp->next = duplicate->next;

            if (duplicate->next != NULL) {
                duplicate->next->prev = temp;
            }

            delete duplicate; 
        } else {
            temp = temp->next;
        }
    }

    return head;
}