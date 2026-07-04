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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;

        // Edge case: empty tree
        if (root == NULL) {
            return result;
        }

        queue<TreeNode*> q;
        q.push(root);

        // Direction flag: true = Left to Right, false = Right to Left
        bool LtoR = true;

        // Perform level order traversal
        while (!q.empty()) {
            int size = q.size();

            // Store nodes of the current level
            vector<int> row(size);

            for (int i = 0; i < size; i++) {
                TreeNode* root = q.front();
                q.pop();

                // Decide the position where current node's value will be stored
                // Normal order if LtoR is true, reverse order otherwise
                int index = (LtoR) ? i : (size - 1 - i);

                row[index] = root->val;

                // Push left child for next level
                if (root->left) {
                    q.push(root->left);
                }

                // Push right child for next level
                if (root->right) {
                    q.push(root->right);
                }
            }

            // Change traversal direction for the next level
            LtoR = !LtoR;

            // Store the completed level
            result.push_back(row);
        }

        return result;
    }
};