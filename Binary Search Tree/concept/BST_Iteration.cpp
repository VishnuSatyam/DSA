class BSTIterator {
private:
    stack<TreeNode*> st;

public:
    BSTIterator(TreeNode* root) {
        // Initially push the entire left boundary.
        // Top of stack = smallest element.
        pushAll(root);
    }

    int next() {

        // Top always contains the next smallest node.
        TreeNode* tempNode = st.top();
        st.pop();

        // After visiting a node,
        // process its right subtree.
        // Push all left nodes of the right subtree.
        pushAll(tempNode->right);

        return tempNode->val;
    }

    bool hasNext() {

        // If stack is not empty,
        // more inorder nodes are available.
        return !st.empty();
    }

private:

    void pushAll(TreeNode* root) {

        // Push the complete left boundary.
        // Leftmost node will be on top.
        while (root != NULL) {

            st.push(root);

            // Keep moving left.
            root = root->left;
        }
    }
};