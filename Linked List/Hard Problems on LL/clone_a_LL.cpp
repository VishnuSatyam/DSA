/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

// brute force approach 

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;

        unordered_map<Node*, Node*> mp;

        Node* temp = head;

        // Step 1: create nodes
        while (temp != NULL) {
            mp[temp] = new Node(temp->val);
            temp = temp->next;
        }

        // Step 2: connect next & random
        temp = head;
        while (temp != NULL) {
            mp[temp]->next = mp[temp->next];
            mp[temp]->random = mp[temp->random];
            temp = temp->next;
        }

        return mp[head];
    }
};


// optimal approach 

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;

        Node* temp = head;

        // Step 1: insert copy nodes
        while (temp != NULL) {
            Node* newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = newNode->next;
        }

        // Step 2: assign random pointers
        temp = head;
        while (temp != NULL) {
            if (temp->random != NULL) {
                temp->next->random = temp->random->next;
            }
            temp = temp->next->next;
        }

        // Step 3: separate lists
        Node* dummy = new Node(0);
        Node* copy = dummy;
        temp = head;

        while (temp != NULL) {
            copy->next = temp->next;
            temp->next = temp->next->next;

            copy = copy->next;
            temp = temp->next;
        }

        return dummy->next;
    }
};