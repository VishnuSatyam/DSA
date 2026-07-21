class Solution {
public:
    TreeNode* build(vector<int>& preorder, int start, int end) {
        if (start > end)
            return NULL;

        TreeNode* root = new TreeNode(preorder[start]);

        int idx = start + 1;

        // Find first element greater than root
        while (idx <= end && preorder[idx] < preorder[start])
            idx++;

        root->left = build(preorder, start + 1, idx - 1);
        root->right = build(preorder, idx, end);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return build(preorder, 0, preorder.size() - 1);
    }
};