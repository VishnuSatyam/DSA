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
    void inorder(TreeNode* root , int &count){
        if(root == NULL) return;
        inorder(root->left , count);
        count++;
        inorder(root->right , count);
    }
    int countNodes(TreeNode* root) {
        int count = 0;
        inorder(root , count);
        return count;
    }
};

// tc and sc is O(n)


// optimal approach using property of complete BT

// we directy compute Nodes=2^h−1 , h is height

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
    int findLeft(TreeNode* root){
        int height = 0;
        while(root){
            height++;
            root = root->left;
        }
        return height;
    }

    int findRight(TreeNode* root){
        int height = 0;
        while(root){
            height++;
            root = root->right;
        }
        return height;
    }
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        int lh = findLeft(root);
        int rh = findRight(root);

        if(lh == rh) return (1<<lh) -1;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

// tc and sc will be O(log n)^2 and O(log n)