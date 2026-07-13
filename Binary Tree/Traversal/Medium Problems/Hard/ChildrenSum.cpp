class Solution {
public:

    void changeTree(BinaryTreeNode<int> *root) {

        // Base case: If tree is empty, do nothing
        if (root == NULL)
            return;

        // Store the sum of left and right child
        int child = 0;

        if (root->left)
            child += root->left->data;

        if (root->right)
            child += root->right->data;

        // ---------------- PREORDER WORK ----------------

        // If children's sum is greater than or equal to parent,
        // increase the parent's value.
        if (child >= root->data) {
            root->data = child;
        }
        else {
            // Otherwise, parent is larger.
            // Push the parent's value down to one of its children.
            // This ensures the Children Sum Property is not violated
            // in the subtree.

            if (root->left)
                root->left->data = root->data;
            else if (root->right)
                root->right->data = root->data;
        }

        // Recursively fix left subtree
        changeTree(root->left);

        // Recursively fix right subtree
        changeTree(root->right);

        // ---------------- POSTORDER WORK ----------------

        // Recalculate children's sum after recursion
        int total = 0;

        if (root->left)
            total += root->left->data;

        if (root->right)
            total += root->right->data; 

        // If current node is not a leaf,
        // update it to the sum of its children.
        if (root->left || root->right)
            root->data = total;
    }
};

// tc and sc will be O(n)  and O(h) respectively.