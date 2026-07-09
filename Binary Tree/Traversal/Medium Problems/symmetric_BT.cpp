// A tree is symmetric if the left subtree is the mirror image
// of the right subtree.
//
// To check this, compare:
//
// Left subtree  : Root -> Left -> Right
// Right subtree : Root -> Right -> Left
//
// At every step:
// 1. Both nodes should be NULL, or
// 2. Both nodes should exist.
// 3. Their values should be equal.
// 4. left->left should match right->right.
// 5. left->right should match right->left.
//
// In other words, we simultaneously traverse one subtree in
// Root -> Left -> Right order and the other in
// Root -> Right -> Left order.
//
// If all corresponding nodes match, the tree is symmetric.


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
    bool isSymmetrical(TreeNode* left , TreeNode* right){
        if(left == NULL || right == NULL) return left == right;

        if(left->val != right->val) return false;

        return isSymmetrical(left->left , right->right) && isSymmetrical(left->right , right->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return isSymmetrical(root->left , root->right);
    }
};