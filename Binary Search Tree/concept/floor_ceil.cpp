// floor 

int floorInBST(TreeNode* root, int key) {
    int floor = -1;

    while (root != nullptr) {

        if (root->val == key)
            return root->val;

        if (root->val > key) {
            root = root->left;
        }
        else {
            floor = root->val;
            root = root->right;
        }
    }

    return floor;
}

// ceil

int ceilInBST(TreeNode* root, int key) {
    int ceil = -1;

    while (root != nullptr) {

        if (root->val == key)
            return root->val;

        if (root->val < key) {
            root = root->right;
        }
        else {
            ceil = root->val;
            root = root->left;
        }
    }

    return ceil;
}