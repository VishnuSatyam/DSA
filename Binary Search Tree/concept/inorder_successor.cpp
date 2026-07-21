/*Inorder Successor — Intuition
Definition

The inorder successor of a node is the next node that appears in inorder traversal.

Remember:

Inorder = Left → Root → Right

So,

Successor = Next bigger element in inorder.

Example
        5
      /   \
     3     8
    / \   / \
   2   4 6   9

   Inorder is

2 3 4 5 6 8 9
Node	Successor
2	    3*/



//brute force appproach 

class Solution {
public:

    void inorder(TreeNode* root, vector<TreeNode*>& ans) {
        if (root == NULL)
            return;

        inorder(root->left, ans);
        ans.push_back(root);
        inorder(root->right, ans);
    }

    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {

        vector<TreeNode*> ans;

        inorder(root, ans);

        for (int i = 0; i < ans.size() - 1; i++) {

            if (ans[i] == p)
                return ans[i + 1];
        }

        return NULL;
    }
};
/*Time Complexity
Inorder : O(n)

Search : O(n)

Total : O(n)

Space

Vector : O(n)*/



// better approach 

class Solution {
public:

    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {

        TreeNode* ans = NULL;

        while (root) {

            if (root->val > p->val) {

                ans = root;        // Greater value -> possible answer -> go left  
                root = root->left; 
            }
            else {

                root = root->right;  // Smaller/equal -> go right
            }
        }

        return ans;
    }
};

// TC: O(h)
// SC: O(1)




// efficient approach


class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {

        TreeNode* successor = NULL;

        while (root != NULL) {

            if (p->val >= root->val) {
                root = root->right;
            }
            else {
                successor = root;
                root = root->left;
            }
        }

        return successor;
    }
};