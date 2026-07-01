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
    int maxDepth(TreeNode* root){
            if(root == NULL) return 0;
            int left = maxDepth(root->left);
            int right = maxDepth(root->right);

            return 1 + max(left , right);
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        
        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);

        if(abs(rh - lh) > 1) return false;

        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);

        return left && right;
    }
};

// tc is O(n^2) and sc is O(n) for recursive stack space

// optimized approach

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
    int maxDepth(TreeNode* root){
            if(root == NULL) return 0;
            int lh = maxDepth(root->left);
            int rh = maxDepth(root->right);

            if(rh == -1 || lh == -1) return -1;
            if(abs(lh - rh)>1) return -1;

            return 1 + max(lh , rh);
    }
    bool isBalanced(TreeNode* root) {

        return maxDepth(root) !=-1;
    }
};
// tc is O(n) and sc is O(n) for recursive stack space