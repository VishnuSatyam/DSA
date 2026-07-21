class Solution {
public:

    void inorder(TreeNode* root, vector<int>& inorderVec) {
        if (root == NULL)
            return;

        inorder(root->left, inorderVec);
        inorderVec.push_back(root->val);
        inorder(root->right, inorderVec);
    }

    bool findTarget(TreeNode* root, int k) {

        vector<int> inorderVec;

        // BST -> Sorted Array
        inorder(root, inorderVec);

        int left = 0;
        int right = inorderVec.size() - 1;

        // Classic Two Sum on sorted array
        while (left < right) {

            int sum = inorderVec[left] + inorderVec[right];

            if (sum == k)
                return true;

            else if (sum < k)
                left++;

            else
                right--;
        }

        return false;
    }
};

//  tc and sc will be O(n) and O(n)



// optimal approach using BST iterator

class BSTIterator {
private:
    stack<TreeNode*> st;
    bool reverse;

public:

    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }

    // Returns next value
    int next() {

        TreeNode* temp = st.top();
        st.pop();

        // Normal inorder
        if (!reverse)
            pushAll(temp->right);

        // Reverse inorder
        else
            pushAll(temp->left);

        return temp->val;
    }

private:

    void pushAll(TreeNode* node) {

        while (node != NULL) {

            st.push(node);

            // Normal inorder -> keep going left
            if (!reverse)
                node = node->left;

            // Reverse inorder -> keep going right
            else
                node = node->right;
        }
    }
};

class Solution {
public:

    bool findTarget(TreeNode* root, int k) {

        if (root == NULL)
            return false;

        // Left iterator (smallest -> largest)
        BSTIterator left(root, false);

        // Right iterator (largest -> smallest)
        BSTIterator right(root, true);

        int i = left.next();
        int j = right.next();

        while (i < j) {

            if (i + j == k)
                return true;

            else if (i + j < k)
                i = left.next();

            else
                j = right.next();
        }

        return false;
    }
};