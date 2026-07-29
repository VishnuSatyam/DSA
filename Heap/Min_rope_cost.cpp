class Solution {
public:
    int minCost(vector<int>& arr) {

        // Min Heap
        priority_queue<int, vector<int>, greater<int>> pq;

        // Insert all ropes
        for (int rope : arr)
            pq.push(rope);

        int cost = 0;

        // Keep connecting until only one rope remains
        while (pq.size() > 1) {

            // Smallest rope
            int first = pq.top();
            pq.pop();

            // Second smallest rope
            int second = pq.top();
            pq.pop();

            // Cost of connecting them
            int sum = first + second;

            // Add to total cost
            cost += sum;

            // Push the new rope back
            pq.push(sum);
        }

        return cost;
    }
};

// tc will be n(logn) and sc will be O(n)