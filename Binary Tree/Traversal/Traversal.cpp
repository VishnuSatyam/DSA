class Solution {
public:
    vector<vector<int>> preInPostTraversal(TreeNode* root) {

        vector<int> pre, in, post;

        if (root == NULL)
            return {pre, in, post};

        stack<pair<TreeNode*, int>> st;
        st.push({root, 1});

        while (!st.empty()) {

            auto it = st.top();
            st.pop();

            // Preorder
            if (it.second == 1) {

                pre.push_back(it.first->val);
                it.second++;
                st.push(it);

                if (it.first->left != NULL) {
                    st.push({it.first->left, 1});
                }
            }

            // Inorder
            else if (it.second == 2) {

                in.push_back(it.first->val);
                it.second++;
                st.push(it);

                if (it.first->right != NULL) {
                    st.push({it.first->right, 1});
                }
            }

            // Postorder
            else {

                post.push_back(it.first->val);
            }
        }

        return {pre, in, post};
    }
};