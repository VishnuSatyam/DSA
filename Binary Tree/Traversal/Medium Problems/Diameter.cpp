// brute force approach 

class Solution {
public:
    int ans = 0;

    int height(TreeNode* root){
        if(root == NULL) return 0;
        int lh = height(root->left);
        int rh = height(root->right);
        return 1 + max(lh , rh);
    }
    void Diameter(TreeNode* root){
        if(root == NULL) return;
        int lh = height(root->left);
        int rh = height(root->right);

        ans = max(ans , lh + rh);

        Diameter(root->left);
        Diameter(root->right);
    }


    int diameterOfBinaryTree(TreeNode* root) {
        Diameter(root);
        return ans;
    }
};

//tc is O(n^2) and sc is O(n) for recursive stack space

// optimized approach

class Solution {
public:
    int diameter = 0;

    int height(TreeNode* root){
        if(root == NULL) return 0;

        int lh = height(root->left);
        int rh = height(root->right);

        diameter = max(diameter, lh + rh);

        return 1 + max(lh, rh);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return diameter;
    }
};