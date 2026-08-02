// brute force 

class Solution {
public:
    vector<int> mergeKArrays(vector<vector<int>> arr, int K) {

        vector<int> ans;

        // Copy all elements
        for (int i = 0; i < K; i++) {
            for (int j = 0; j < arr[i].size(); j++) {
                ans.push_back(arr[i][j]);
            }
        }

        // Sort all elements
        sort(ans.begin(), ans.end());

        return ans;
    }
};


// optimal

/*Intuition

Suppose you have:

A1 = [1, 4, 7]
A2 = [2, 5, 8]
A3 = [3, 6, 9]

Each array is already sorted.

Initially, the smallest element of the final answer must be one of the first elements:

1, 2, 3

So instead of putting all 9 elements into the heap, we only put the first element of each array.

Every time we remove the smallest element, we insert the next element from the same array.

Thus, the heap size never exceeds K.*/


class Node {
public:
    int data;
    int row;
    int col;

    Node(int data, int row, int col) {
        this->data = data;
        this->row = row;
        this->col = col;
    }
};

class compare {
public:
    bool operator()(Node* a, Node* b) {
        return a->data > b->data;   // Min Heap
    }
};

class Solution {
public:
    vector<int> mergeKArrays(vector<vector<int>> arr, int K) {

        priority_queue<Node*, vector<Node*>, compare> pq;

        // Insert first element of every array
        for (int i = 0; i < K; i++) {
            pq.push(new Node(arr[i][0], i, 0));
        }

        vector<int> ans;

        while (!pq.empty()) {

            Node* temp = pq.top();
            pq.pop();

            ans.push_back(temp->data);

            int row = temp->row;
            int col = temp->col;

            // Insert next element from same array
            if (col + 1 < arr[row].size()) {
                pq.push(new Node(arr[row][col + 1], row, col + 1));
            }
        }

        return ans;
    }
};

// tc and sc will be O(nklogk) and O(k) respectively where n is the number of elements in each array and k is the number of arrays.