// basic approach using inorder traversal 

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
    void inorder(TreeNode* root, vector<int> &ans){
        if(root == NULL) return;

        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans;
        inorder(root , ans);
        return ans[k-1]; // since inorder of a  bst is always sorted 
    }
};

// tc and sc is O(n)

// to avoid extra space which we are using we can use a counter as hits k we return node 


class Solution {
public:
    int ans = -1;

    void inorder(TreeNode* root, int& k) {
        if (root == NULL) return;

        inorder(root->left, k);

        k--;                        // Visited one node
        if (k == 0) {               // This is the kth smallest
            ans = root->val;
            return;
        }

        inorder(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return ans;
    }
};

/* TC is O(h + k) average, O(n) worst    and sc is O(h)*/


// by using morris traversal we can make sc  as O(1)


class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {

        TreeNode* curr = root;

        while (curr != NULL) {

            // No left subtree
            if (curr->left == NULL) {

                k--;
                if (k == 0)
                    return curr->val;

                curr = curr->right;
            }

            // Left subtree exists
            else {

                // Find inorder predecessor
                TreeNode* prev = curr->left;

                while (prev->right != NULL && prev->right != curr)
                    prev = prev->right;

                // First time visiting curr
                if (prev->right == NULL) {

                    prev->right = curr;      // Create thread
                    curr = curr->left;
                }

                // Second time visiting curr
                else {

                    prev->right = NULL;      // Remove thread

                    k--;
                    if (k == 0)
                        return curr->val;

                    curr = curr->right;
                }
            }
        }

        return -1;
    }
};





// for finding kth largest we can just do n-k+1 smallest which will be equivalent to finding kth largest 


class Solution {
public:
    int ans = -1;

    // Count total nodes
    int countNodes(TreeNode* root) {
        if (root == NULL)
            return 0;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    // Inorder traversal to find kth smallest
    void inorder(TreeNode* root, int& k) {
        if (root == NULL)
            return;

        inorder(root->left, k);

        if (--k == 0) {
            ans = root->val;
            return;
        }

        inorder(root->right, k);
    }

    int kthLargest(TreeNode* root, int k) {

        int n = countNodes(root);

        // Convert kth largest to kth smallest
        k = n - k + 1;

        inorder(root, k);

        return ans;
    }
};