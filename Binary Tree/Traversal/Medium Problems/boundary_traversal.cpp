/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:

    // Check whether a node is a leaf
    bool isLeaf(TreeNode* root) {
        return (root->left == NULL && root->right == NULL);
    }

    // Add all left boundary nodes (excluding leaf nodes)
    void addLeftBoundary(TreeNode* root, vector<int>& ans) {
        TreeNode* curr = root->left;

        while (curr) {
            if (!isLeaf(curr))
                ans.push_back(curr->val);

            // Prefer left child, otherwise move to right child
            if (curr->left)
                curr = curr->left;
            else
                curr = curr->right;
        }
    }

    // Add all leaf nodes using DFS
    void addLeaves(TreeNode* root, vector<int>& ans) {
        if (root == NULL)
            return;

        if (isLeaf(root)) {
            ans.push_back(root->val);
            return;
        }

        addLeaves(root->left, ans);
        addLeaves(root->right, ans);
    }

    // Add right boundary nodes in reverse order (excluding leaf nodes)
    void addRightBoundary(TreeNode* root, vector<int>& ans) {
        TreeNode* curr = root->right;
        vector<int> temp;

        while (curr) {
            if (!isLeaf(curr))
                temp.push_back(curr->val);

            // Prefer right child, otherwise move to left child
            if (curr->right)
                curr = curr->right;
            else
                curr = curr->left;
        }

        // Add nodes in reverse order
        for (int i = temp.size() - 1; i >= 0; i--) {
            ans.push_back(temp[i]);
        }
    }

    vector<int> boundary(TreeNode* root) {
        vector<int> ans;

        if (root == NULL)
            return ans;

        // Add root if it is not a leaf
        if (!isLeaf(root))
            ans.push_back(root->val);

        // Step 1: Left Boundary
        addLeftBoundary(root, ans);

        // Step 2: All Leaf Nodes
        addLeaves(root, ans);

        // Step 3: Right Boundary (in reverse)
        addRightBoundary(root, ans);

        return ans;
    }
};