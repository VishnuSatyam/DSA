class Solution {
public:
    // Store inorder traversal
    void storeInorder(Node* root, vector<int>& inorder) {
        if (root == NULL)
            return;

        storeInorder(root->left, inorder);
        inorder.push_back(root->data);
        storeInorder(root->right, inorder);
    }

    // Fill nodes using preorder traversal
    void fillPreorder(Node* root, vector<int>& inorder, int& index) {
        if (root == NULL)
            return;

        // Assign next smallest value
        root->data = inorder[index++];

        fillPreorder(root->left, inorder, index);
        fillPreorder(root->right, inorder, index);
    }

    void convertToMinHeapUtil(Node* root) {
        vector<int> inorder;

        // Step 1: Get sorted values
        storeInorder(root, inorder);

        // Step 2: Fill tree in preorder
        int index = 0;
        fillPreorder(root, inorder, index);
    }
};