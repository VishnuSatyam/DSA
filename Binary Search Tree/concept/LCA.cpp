/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        // Base case
        if (root == NULL) return NULL;

        int curr = root->val;

        // Both nodes are greater than current,
        // so LCA must lie in the right subtree.
        if (curr < p->val && curr < q->val) {
            return lowestCommonAncestor(root->right, p, q);
        }

        // Both nodes are smaller than current,
        // so LCA must lie in the left subtree.
        if (curr > p->val && curr > q->val) {
            return lowestCommonAncestor(root->left, p, q);
        }

        // Split point:
        // One node lies on the left and the other on the right,
        // OR one of p/q is the current node itself.
        // Hence, current node is the Lowest Common Ancestor.
        return root;
    }
};