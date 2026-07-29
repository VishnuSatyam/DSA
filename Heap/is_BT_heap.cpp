class Solution {
public:

    int countNodes(Node* root) {
        if (root == NULL)
            return 0;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    bool isCBT(Node* root, int index, int totalNodes) {

        if (root == NULL)
            return true;

        if (index >= totalNodes)
            return false;

        return isCBT(root->left, 2 * index + 1, totalNodes) &&
               isCBT(root->right, 2 * index + 2, totalNodes);
    }

    bool isMaxOrder(Node* root) {

        // Leaf node
        if (root->left == NULL && root->right == NULL)
            return true;

        // Only left child
        if (root->right == NULL)
            return root->data >= root->left->data;

        bool left = isMaxOrder(root->left);
        bool right = isMaxOrder(root->right);

        return left && right &&
               (root->data >= root->left->data) &&
               (root->data >= root->right->data);
    }

    bool isHeap(Node* tree) {

        int totalNodes = countNodes(tree);

        return isCBT(tree, 0, totalNodes) &&
               isMaxOrder(tree);
    }
};

//tc and sc will be O(n) 