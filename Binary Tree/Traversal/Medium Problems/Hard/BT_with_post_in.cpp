class Solution {
public:
    unordered_map<int, int> inorderMap;
    int postIndex;

    TreeNode* build(vector<int>& postorder, int left, int right) {

        // Base case
        if (left > right)
            return NULL;

        // Current root
        int rootVal = postorder[postIndex--];

        TreeNode* root = new TreeNode(rootVal);

        // Find root position in inorder
        int mid = inorderMap[rootVal];

        // IMPORTANT: build right first
        root->right = build(postorder, mid + 1, right);

        // Then build left
        root->left = build(postorder, left, mid - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        for (int i = 0; i < inorder.size(); i++)
            inorderMap[inorder[i]] = i;

        postIndex = postorder.size() - 1;

        return build(postorder, 0, inorder.size() - 1);
    }
};

/*Root = last element of postorder
↓
Split using inorder
↓
Build Right then Left*/

// tc and sc will be O(n)