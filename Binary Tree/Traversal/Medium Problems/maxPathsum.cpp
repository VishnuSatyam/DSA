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
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;          // Stores the maximum path sum found so far
        maxPathDown(root, maxi);
        return maxi;
    }

    int maxPathDown(TreeNode* root, int &maxi) {
        if (root == NULL) return 0;

        // Ignore negative path sums since they only decrease the answer
        int left = max(0, maxPathDown(root->left, maxi));
        int right = max(0, maxPathDown(root->right, maxi));

        // Path passing through current node (left + root + right)
        maxi = max(maxi, left + right + root->val);

        // Return the best single path extending upward to the parent
        return max(left, right) + root->val;
    }
};