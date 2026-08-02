/*Algorithm
Traverse every linked list.
Store all node values in a vector.
Sort the vector.
Create a new linked list using the sorted values.
Return the head of the new list.*/

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> arr;

        for (ListNode* head : lists) {
            while (head) {
                arr.push_back(head->val);
                head = head->next;
            }
        }

        sort(arr.begin(), arr.end());

        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        for (int x : arr) {
            temp->next = new ListNode(x);
            temp = temp->next;
        }

        return dummy->next;
    }
};

/*Time Complexity: O(N log N)

Space Complexity: O(N) (vector + new linked list)*/



// optimal approach

/*he optimal approach is to use a Min Heap (Priority Queue).

Idea

Since each linked list is already sorted:

Put the first node of every list into a min heap.
The heap always gives you the smallest node among all current nodes.
Remove the smallest node, add it to the answer, then insert its next node (if it exists).
Repeat until the heap is empty.
Example

Suppose

List1: 1 -> 4 -> 5
List2: 1 -> 3 -> 4
List3: 2 -> 6
Step 1

Insert the first node of every list.

Heap:
1(L1)
1(L2)
2(L3)

Answer:

dummy
Step 2

Pop the smallest.

pop 1(L1)

Answer:

1

Now insert its next node (4).

Heap:
1(L2)
2(L3)
4(L1)
Step 3

Pop again.

pop 1(L2)

Answer:

1 -> 1

Insert next node (3).

Heap:
2
3
4
Step 4

Pop 2.

Answer

1 -> 1 -> 2

Insert next node (6).

Heap:
3
4
6
Step 5

Pop 3.

Answer

1 -> 1 -> 2 -> 3

Insert next node (4).

Heap:
4
4
6

Continue until the heap becomes empty.

Final Answer

1 -> 1 -> 2 -> 3 -> 4 -> 4 -> 5 -> 6*/

class cmp {
public:
    // Comparator for min heap
    // Node with smaller value gets higher priority
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        // Min heap storing ListNode pointers
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;

        // Push the first node of every non-empty list
        for (ListNode* head : lists) {
            if (head)
                pq.push(head);
        }

        // Dummy node to simplify list construction
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        // Process until all nodes are merged
        while (!pq.empty()) {

            // Get the smallest node
            ListNode* node = pq.top();
            pq.pop();

            // Attach it to the merged list
            temp->next = node;
            temp = temp->next;

            // Push the next node from the same list (if it exists)
            if (node->next)
                pq.push(node->next);
        }

        // Return the head of the merged list
        return dummy->next;
    }
};

// tc and sc is O(N log k) and O(k) respectively