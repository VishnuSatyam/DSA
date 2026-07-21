// brute force approach 

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isBST(TreeNode* root, long long mini, long long maxi){
        if(root == NULL) return true;

        if(root->val <=mini || root->val >= maxi) return false;

        return isBST(root->left, mini, root->val) && isBST(root->right, root->val, maxi);
    }

    int sumNodes(TreeNode* root){
        if(root == NULL) return 0;

        return root->val + sumNodes(root->left) + sumNodes(root->right);
    }

    int solve(TreeNode* root){
        if(root == NULL) return 0;

        int left = solve(root->left);
        int right = solve(root->right);

        int curr = INT_MIN;

        if(isBST(root, LLONG_MIN, LLONG_MAX)) curr = sumNodes(root);      

        return max(curr, max(left, right));
    }
    int maxSumBST(TreeNode* root) {
        return max(0, solve(root));
    }
};

// Time Complexity: O(N²)
//Space Complexity: O(H) (Worst case O(N))
// tle will come 




//optimal approach 

class NodeValue
{
public:
    int minNode;
    int maxNode;
    int maxSum;

    NodeValue(int mn,int mx,int sum)
    {
        minNode = mn;
        maxNode = mx;
        maxSum = sum;
    }
};

class Solution {
public:

    int ans = 0;

    NodeValue helper(TreeNode* root)
    {
        if(root==NULL)
            return NodeValue(INT_MAX,INT_MIN,0);

        NodeValue left = helper(root->left);
        NodeValue right = helper(root->right);

        if(left.maxNode < root->val &&
           root->val < right.minNode)
        {
            int currSum =
                left.maxSum +
                right.maxSum +
                root->val;

            ans = max(ans,currSum);

            return NodeValue(
                min(left.minNode,root->val),
                max(right.maxNode,root->val),
                currSum
            );
        }

        return NodeValue(
            INT_MIN,
            INT_MAX,
            0
        );
    }

    int maxSumBST(TreeNode* root)
    {
        helper(root);
        return ans;
    }
};

//tc and sc will be O(N) and O(h) (Worst: O(N))