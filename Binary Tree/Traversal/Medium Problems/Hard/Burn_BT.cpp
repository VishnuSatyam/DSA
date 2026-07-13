/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:

    // Stores parent of every node
    unordered_map<TreeNode*, TreeNode*> parent;

    // Build parent map and return pointer to start node
    TreeNode* markParents(TreeNode* root, int start) {

        queue<TreeNode*> q;
        q.push(root);

        TreeNode* target = nullptr;

        while (!q.empty()) {

            TreeNode* curr = q.front();
            q.pop();

            // Found the starting node
            if (curr->val == start)
                target = curr;

            if (curr->left) {
                parent[curr->left] = curr;
                q.push(curr->left);
            }

            if (curr->right) {
                parent[curr->right] = curr;
                q.push(curr->right);
            }
        }

        return target;
    }

    int amountOfTime(TreeNode* root, int start) {

        // Step 1: Build parent map and locate start node
        TreeNode* target = markParents(root, start);

        // Step 2: BFS to spread infection
        queue<TreeNode*> q;
        unordered_map<TreeNode*, bool> visited;

        q.push(target);
        visited[target] = true;

        int time = 0;

        while (!q.empty()) {

            int size = q.size();

            bool burnedNewNode = false;

            while (size--) {

                TreeNode* curr = q.front();
                q.pop();

                // Left child
                if (curr->left && !visited[curr->left]) {
                    visited[curr->left] = true;
                    q.push(curr->left);
                    burnedNewNode = true;
                }

                // Right child
                if (curr->right && !visited[curr->right]) {
                    visited[curr->right] = true;
                    q.push(curr->right);
                    burnedNewNode = true;
                }

                // Parent
                if (parent.count(curr) && !visited[parent[curr]]) {
                    visited[parent[curr]] = true;
                    q.push(parent[curr]);
                    burnedNewNode = true;
                }
            }

            // If fire spread this second, increment time
            if (burnedNewNode)
                time++;
        }

        return time;
    }
};


/* ALGORITHM:

1. Traverse the tree.
      |
      |-- Build parent map.
      |-- Find target node.

2. Start BFS from target.

3. At every level:
      Visit left
      Visit right
      Visit parent

4. Increase time after finishing one level.

5. When queue becomes empty,
   return time.

*/

// tc and sc will be O(n)