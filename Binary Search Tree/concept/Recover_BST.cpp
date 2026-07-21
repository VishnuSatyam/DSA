// brute force approach

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
    void store(TreeNode* root, vector<int>& inorder){
        if(root == NULL) return;

        store(root->left, inorder);
        inorder.push_back(root->val);
        store(root->right, inorder);
    }

    void recover(TreeNode* root, vector<int>& inorder, int &index){
        if(root == NULL) return;

        recover(root->left, inorder, index);

        if(root->val != inorder[index]) root->val = inorder[index];
        index++;

        recover(root->right, inorder, index);
    }
    void recoverTree(TreeNode* root) {
        vector<int> inorder;
        store(root, inorder);
        sort(inorder.begin(), inorder.end());

        int index = 0;
        recover(root, inorder, index);
    }
};

// First inorder : O(n)

// Sorting : O(n log n)

// Second inorder : O(n)

// Total : O(n log n)

// Space : O(n)



// optimal approach 

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
private:
    TreeNode* first;
    TreeNode* prev;
    TreeNode* middle;
    TreeNode* last;

private:
    void inorder(TreeNode* root){
        if(root == NULL)   return;
        inorder(root->left);

        if(prev != NULL && (root->val < prev->val)){
            if(first == NULL){
                first = prev;
                middle = root;
            }
            else{
                last = root;
            }
        }
        prev = root;
        inorder(root->right);
    }    
public:
    void recoverTree(TreeNode* root) {
        first = middle = last = NULL;

        prev = new TreeNode(INT_MIN);
        inorder(root);

        if(first && last) swap(first->val, last->val);
        else if(first && middle) swap(first->val, middle->val);
    }
};