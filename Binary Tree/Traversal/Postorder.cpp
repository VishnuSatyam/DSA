//  iterative aproach using 2 stack

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;

        stack<TreeNode*> s1 , s2;
        s1.push(root);
        while(!s1.empty()){
            TreeNode* curr = s1.top();
            s1.pop();
            s2.push(curr);

            if(curr->left != NULL) s1.push(curr->left);
            if(curr->right != NULL) s1.push(curr->right);
        }
        
        while(!s2.empty()){
            ans.push_back(s2.top()->val);
            s2.pop();
        }
        return ans;
    }
};

// tc will be O(n) and sc will be O(n)


// using one stack 

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {

        vector<int> ans;

        if (root == NULL)
            return ans;

        stack<TreeNode*> st;
        TreeNode* curr = root;

        while (curr != NULL || !st.empty()) {

            if (curr != NULL) {
                st.push(curr);
                curr = curr->left;
            }
            else {

                TreeNode* temp = st.top()->right;

                if (temp == NULL) {

                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->val);

                    while (!st.empty() && temp == st.top()->right) {
                        temp = st.top();
                        st.pop();
                        ans.push_back(temp->val);
                    }
                }
                else {
                    curr = temp;
                }
            }
        }

        return ans;
    }
};

// tc and sc will be O(2n)