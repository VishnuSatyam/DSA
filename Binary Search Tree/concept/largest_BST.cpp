//  brute force approach (O(N²))
/*The idea is simple:

For every node, assume it is the root of a subtree.

Check if that subtree is a BST.
If yes, count its nodes.
If not, recursively find the largest BST in its left and right subtree.*/

class Solution
{
public:

    bool isBST(TreeNode* root, long long minVal, long long maxVal)
    {
        if (root == NULL)
            return true;

        if (root->val <= minVal || root->val >= maxVal)
            return false;

        return isBST(root->left, minVal, root->val) &&
               isBST(root->right, root->val, maxVal);
    }

    int countNodes(TreeNode* root)
    {
        if (root == NULL)
            return 0;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    int largestBST(TreeNode* root)
    {
        if (root == NULL)
            return 0;

        if (isBST(root, LLONG_MIN, LLONG_MAX))
            return countNodes(root);

        return max(largestBST(root->left),
                   largestBST(root->right));
    }
};




// optimal approch
/*Instead of checking BST repeatedly,

while coming back from recursion,

return enough information so parent immediately knows whether it forms a BST.

This makes every node visited only once.*/

class NodeValue
{
public:
    int minNode, maxNode, maxSize;

    NodeValue(int minNode, int maxNode, int maxSize)
    {
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->maxSize = maxSize;
    }
};

class Solution
{
public:
    NodeValue helper(TreeNode* root)
    {
        if (root == NULL)
            return NodeValue(INT_MAX, INT_MIN, 0);

        auto left = helper(root->left);
        auto right = helper(root->right);

        // Current subtree is BST
        if (left.maxNode < root->val && root->val < right.minNode)
        {
            return NodeValue(
                min(left.minNode, root->val),
                max(right.maxNode, root->val),
                left.maxSize + right.maxSize + 1
            );
        }

        // Not BST
        return NodeValue(
            INT_MIN,
            INT_MAX,
            max(left.maxSize, right.maxSize)
        );
    }

    int largestBSTSubtree(TreeNode* root)
    {
        return helper(root).maxSize;
    }
};