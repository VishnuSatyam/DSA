/*Idea

Normally, inorder traversal needs a way to return to a node after visiting its left subtree.

We usually use:

Recursion → Call Stack
Stack → Explicit Stack

Morris Traversal does something clever:

Temporarily connect the inorder predecessor to the current node.

This temporary connection is called a thread.*/


/*Case 1

No left child

curr

  5
   \
    8

Since nothing exists on the left,

visit it immediately.

ans.push_back(curr->val);

curr = curr->right;*/




/*Case 2

Left child exists

Find predecessor.

Example

        4
       /
      2
     / \
    1   3

Predecessor

3

Now two possibilities.*/

/*Case 2A

Thread doesn't exist.

3 -> NULL

Create it.

3 -----> 4

Move left.

curr = curr->left;


Case 2B

Thread already exists.

3 -----> 4

This means

Left subtree has already been completely visited.

Now

Remove thread.

3 -> NULL

Visit current node.

Move right.


*/

        4
      /   \
     2     6
    / \
   1   3


class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {

        vector<int> ans;
        TreeNode* curr = root;

        while (curr != NULL) {

            // Case 1: No left subtree
            if (curr->left == NULL) {
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else {

                // Find inorder predecessor (rightmost node of left subtree)
                TreeNode* prev = curr->left;

                while (prev->right != NULL && prev->right != curr)
                    prev = prev->right;

                // First time visiting this subtree
                if (prev->right == NULL) {
                    prev->right = curr;      // Create thread
                    curr = curr->left;
                }
                else {

                    // Left subtree already processed
                    prev->right = NULL;      // Remove thread

                    ans.push_back(curr->val);

                    curr = curr->right;
                }
            }
        }

        return ans;
    }
};

//tc will be O(n) and sc will be O(1)


// for preorder morris traversal 

/*Morris Preorder is almost identical to Morris Inorder.

There is only one difference:

When do we visit the current node?

Let's compare them.

Inorder

Traversal is

Left → Root → Right

So we visit the node after finishing the left subtree.

That's why in Morris Inorder:

// No left child
ans.push_back(curr->val);

// Thread exists
prev->right = NULL;
ans.push_back(curr->val);

Notice that we visit after returning from the left subtree.

Preorder

Traversal is

Root → Left → Right

So we should visit the node before going to the left subtree.

That changes only one place.*/

vector<int> preorderTraversal(TreeNode* root) {

    vector<int> ans;
    TreeNode* curr = root;

    while(curr){

        if(curr->left == NULL){

            ans.push_back(curr->val);

            curr = curr->right;
        }
        else{

            TreeNode* prev = curr->left;

            while(prev->right && prev->right != curr)
                prev = prev->right;

            if(prev->right == NULL){

                ans.push_back(curr->val);   // Difference

                prev->right = curr;

                curr = curr->left;
            }
            else{

                prev->right = NULL;

                curr = curr->right;
            }
        }
    }

    return ans;
}

// tc and sc will be O(n) and O(1)