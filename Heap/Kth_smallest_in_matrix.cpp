// brute force approach (flatten and sort)

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> v;
        for(auto &row : matrix){
            for(auto x : row){
                v.push_back(x);
            }
        }
        sort(v.begin(), v.end());

        return v[k-1];
    }
};


// Approach 2 , using min heap

/*Since every row is sorted,

1  5  9
10 11 13
12 13 15

the smallest element of every row is

1
10
12

Push only these into the heap.

Heap contains

1
10
12

Pop smallest.

1
Answer not yet.

Now insert the next element from the same row.

5

Heap

5
10
12

Again pop.

5

Insert

9

Continue until you've popped exactly k elements.

The kth pop is the answer.*/

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();

        // Min Heap stores {value, row, col}
        // 'value' decides the heap order (smallest value stays at the top).
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        // Insert the first element of every row into the heap.
        // Since each row is sorted, these are the smallest candidates
        // from their respective rows.
        for (int i = 0; i < n; i++) {
            pq.push({matrix[i][0], i, 0});
        }

        // Remove the smallest element (k-1) times.
        // After these pops, the heap top will be the kth smallest element.
        while (--k) {

            // Get the current smallest element.
            auto temp = pq.top();
            pq.pop();

            int val = temp[0];   // Current smallest value (not used further)
            int row = temp[1];   // Row from which this value came
            int col = temp[2];   // Column of this value

            // Push the next element from the same row (if it exists).
            // This keeps exactly one active candidate from each row in the heap.
            if (col + 1 < n) {
                pq.push({matrix[row][col + 1], row, col + 1});
            }
        }

        // After removing (k-1) smallest elements,
        // the heap top is the kth smallest.
        return pq.top()[0];
    }
};