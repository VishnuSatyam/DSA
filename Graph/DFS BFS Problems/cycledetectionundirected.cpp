/*
Here are your revision notes for **Detecting a Cycle in an Undirected Graph using BFS**.

### The Core Intuition

The entire logic relies on the concept of a **collision** between two different paths.
When doing a Breadth-First Search (BFS), you radiate outward level by level. If a cycle exists, two different paths will eventually attempt to visit the exact same node from different directions.

**The Golden Rule:** If you are at a current node and you see an adjacent node that is **already marked as visited**, and that adjacent node is **NOT the parent** (the node you just came from), it means someone else in the BFS traversal already reached it. You have found a cycle!

### The Setup

To execute this, standard BFS isn't enough because you need to remember where you came from so you don't falsely identify going back to your immediate previous node as a cycle.

* **Queue structure:** Instead of just pushing the node into the queue, push a pair: `(currentNode, parentNode)`.
* **Source node:** For the starting node, its parent doesn't exist, so you push `(sourceNode, -1)`.

### Step-by-Step Algorithm

1. **Initialize your structures:** Prepare the Queue and Visited Array.
Create a `visited` array (initialized to 0/false for all nodes) and a Queue that will store pairs of integers `(node, parent)`.


2. **Start the BFS:**
Push your starting node into the queue as `(startNode, -1)` and mark the `startNode` as visited in your array.


3. **Process the Queue:**
While the queue is not empty, pop the front pair `(node, parent)`.


4. **Traverse Adjacent Nodes:**
Iterate through all the adjacent nodes of your popped `node`. For each adjacent node:

* **Condition 1 (Not Visited):** If it hasn't been visited, mark it as visited and push `(adjacentNode, node)` into the queue.
* **Condition 2 (Cycle Detected):** If it *has* been visited AND `adjacentNode != parent`, return **True** immediately. A cycle exists.
* **Condition 3 (It is the parent):** If it has been visited but it *is* the parent, do nothing. You just came from there.


### Handling Disconnected Components

A graph might have multiple disconnected parts, and a cycle could be hiding in any of them.

* Don't just run BFS from node 1 and stop.
* Wrap your BFS logic in a `for` loop that iterates from `1` to `N` (or `0` to `N-1` depending on indexing).
* If `visited[i] == false`, call your BFS function on `i`. If any of those calls return true, the graph has a cycle.

### Complexity Analysis

* **Time Complexity:** `O(N + 2E)` where `N` is the number of nodes and `E` is the number of edges. This is because every node is added to the queue once, and the inner loop runs for the sum of the degrees of all nodes (which is twice the number of edges in an undirected graph).
* **Space Complexity:** `O(N)` for both the `visited` array and the Queue data structure.
*/



class Solution {
    private:
    bool bfs(int start, int V, vector<int> adj[], vector<bool> &visited) {
        queue<pair<int, int>> q;  // (node, parent)
        visited[start] = true;
        q.push({start, -1});

        while (!q.empty()) {
            auto [current, parent] = q.front();
            q.pop();

            for (int neighbor : adj[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push({neighbor, current});
                } else if (neighbor != parent) {
                    return true;  // Cycle detected
                }
            }
        }
        return false;
    }

public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (bfs(i, V, adj, visited)) {
                    return true;  // Cycle found
                }
            }
        }
        return false;  // No cycle found in any component
    }
};

// tc will be O(V+2E)=O(V+E)​
// sc will be O(V) for visited array and queue