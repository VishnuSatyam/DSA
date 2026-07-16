// minimum 
// iterative approach (preferred)
TreeNode* findMin(TreeNode* root) {
    if (root == nullptr)
        return nullptr;

    while (root->left != nullptr)
        root = root->left;

    return root;
}

// recursive approach
TreeNode* findMin(TreeNode* root) {
    if (root == nullptr || root->left == nullptr)
        return root;

    return findMin(root->left);
}


// maximum

// iterative approach 

TreeNode* findMax(TreeNode* root) {
    if (root == nullptr)
        return nullptr;

    while (root->right != nullptr)
        root = root->right;

    return root;
}

// recursive approach 

TreeNode* findMax(TreeNode* root) {
    if (root == nullptr || root->right == nullptr)
        return root;

    return findMax(root->right);
}