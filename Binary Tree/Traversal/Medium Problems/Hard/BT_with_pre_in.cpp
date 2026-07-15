class Solution {
public:
    unordered_map<int, int> inorderMap;
    int preIndex = 0;

    TreeNode* build(vector<int>& preorder, int left, int right) {

        // Base case: no elements in this inorder range
        if (left > right)
            return NULL;

        // Current root from preorder
        int rootVal = preorder[preIndex++];

        TreeNode* root = new TreeNode(rootVal);

        // Find root position in inorder
        int mid = inorderMap[rootVal];

        // Build left subtree
        root->left = build(preorder, left, mid - 1);

        // Build right subtree
        root->right = build(preorder, mid + 1, right);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        // Store inorder indices
        for (int i = 0; i < inorder.size(); i++)
            inorderMap[inorder[i]] = i;

        return build(preorder, 0, inorder.size() - 1);
    }
};

//tc and sc will be O(n)
/*
Preorder + Inorder uniquely determine a binary tree only if all node values are unique.
*/

/*Root = first element of preorder
↓
Split using inorder
↓
Build Left then Right*/