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

        // Base Case 1:
        // Reached the end of a path without finding either node.
        if (root == NULL) return NULL;

        // Base Case 2:
        // If current node is either p or q, return it.
        // This acts as a signal to the parent that one target has been found.
        if (root->val == p->val || root->val == q->val) {
            return root;
        }

        // Search for p and q in the left subtree.
        TreeNode* leftLCA = lowestCommonAncestor(root->left, p, q);

        // Search for p and q in the right subtree.
        TreeNode* rightLCA = lowestCommonAncestor(root->right, p, q);

        // Intuition:
        // ---------------------------------------------------------
        // 1. If both left and right return non-NULL,
        //    it means one node was found in the left subtree
        //    and the other in the right subtree.
        //    Hence, current node is the Lowest Common Ancestor.
        if (leftLCA && rightLCA) {
            return root;
        }

        // 2. If only the left subtree returned a node,
        //    both p and q lie in the left subtree
        //    (or left itself is the answer).
        else if (leftLCA != NULL) {
            return leftLCA;
        }

        // 3. Otherwise, only the right subtree returned a node,
        //    so propagate that answer upward.
        else {
            return rightLCA;
        }
    }
};

// tc and sc will be O(N)