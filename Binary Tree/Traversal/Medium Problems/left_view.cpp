/*
For the Left View, you simply reverse the child visiting order.

Right View: Root → Right → Left
Left View: Root → Left → Right
*/

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
    void recursion(TreeNode* root, int level, vector<int>& res) {
        if (root == NULL) return;

        // First node visited at this level
        if (res.size() == level)
            res.push_back(root->val);

        recursion(root->left, level + 1, res);
        recursion(root->right, level + 1, res);
    }

    vector<int> leftSideView(TreeNode* root) {
        vector<int> res;
        recursion(root, 0, res);
        return res;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(H), where H is the height of the tree