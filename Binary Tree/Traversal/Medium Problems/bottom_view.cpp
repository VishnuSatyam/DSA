// using level order traversal and map to store the first node at each horizontal distance also we are using same intution as vertical order traversal but we are storing only first node at each horizontal distance and then we are returning the values of map in sorted order of keys.
// last node on every level of the tree is visible from bottom view of binary tree

class Solution {
public:
    vector<int> bottomView(Node *root) {
        vector<int> ans;

        if (root == NULL)
            return ans;

        map<int, int> mpp;
        queue<pair<Node*, int>> q;

        q.push({root, 0});

        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            Node* node = it.first;
            int line = it.second;

            mpp[line] = node->data;

            if (node->left != NULL) {
                q.push({node->left, line - 1});
            }

            if (node->right != NULL) {
                q.push({node->right, line + 1});
            }
        }

        for (auto it : mpp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};

// tc: O(nlogn) + O(n) + O(n) ~ O(nlogn) and sc: O(n) + O(n) ~ O(n)