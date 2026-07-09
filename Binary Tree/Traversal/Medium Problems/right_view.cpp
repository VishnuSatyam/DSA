// Last node of every level will be our RIGHT VIEW
// if level order traversal is done from left to right.

// First node of every level will be our RIGHT VIEW
// if level order traversal is done from right to left.


// we will be doing reverse preorder traversal which is root->right->left (we reverse the order of visiting the children, not the entire traversal.) . with this first node we get in every right will be part of right view

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
    void recursion(TreeNode* root, int level , vector<int> & res){
        if(root == NULL) return;
        if(res.size()== level) res.push_back(root->val);

        recursion(root->right , level+1 , res);
        recursion(root->left , level+1 , res);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        recursion(root , 0 , res);
        return res;
    }
};

// tc is o(n) and sc is o(h) where h is height of tree