// recursive approach // kinda using reverse postorder
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
    TreeNode* prev = NULL;
    void flatten(TreeNode* root) {
        if(root == NULL) return;

        flatten(root->right);
        flatten(root->left);

        root->right = prev;
        root->left = NULL;

        prev = root;

    }
};

// tc and sc will be O(n)


// iterative approach  !so imp

void flatten(TreeNode* root) {

    if(root == NULL) return;

    stack<TreeNode*> st;
    st.push(root);

    while(!st.empty()){

        TreeNode* curr = st.top();
        st.pop();

        // Push right first because stack is LIFO
        if(curr->right)
            st.push(curr->right);

        // Left will be processed before right
        if(curr->left)
            st.push(curr->left);

        // Connect current node to next preorder node
        if(!st.empty())
            curr->right = st.top();

        // Flatten into linked list
        curr->left = NULL;
    }
}

// tc ans sc is O(n)

/*Whenever we see preorder + stack, remember:

"Push Right first, then Left."

That one rule makes the rest of the algorithm fall into place.*/


// best approach using morris traversal

TreeNode* curr = root;

while (curr != NULL) {

    if (curr->left != NULL) {

        TreeNode* prev = curr->left;

        while (prev->right != NULL) {
            prev = prev->right;
        }

        prev->right = curr->right;
        curr->right = curr->left;
        curr->left = NULL;
    }

    curr = curr->right;
}