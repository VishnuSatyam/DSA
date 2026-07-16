/*The idea is simple:

Find the node to delete.
Handle one of three cases.*/

/*Case 1: Node has no children (Leaf)

Just delete it.

    5
   /
  3

Delete 3

    5

Return NULL.*/


/*Case 2: Node has one child

Replace the node with its child.

Only Left Child
      5
     /
    3
   /
  2

Delete 3

      5
     /
    2

Return root->left.

Only Right Child
    5
     \
      8
       \
        9

Delete 8

    5
     \
      9

Return root->right.
*/



/*Case 3: Node has two children ⭐

This is the interesting case.

We cannot simply delete the node because we'd lose one subtree.

Instead:

Find the inorder successor (smallest node in the right subtree), or
Find the inorder predecessor (largest node in the left subtree).

Most interview solutions use the inorder successor.

Example
        8
      /   \
     5     12
          /  \
        10   15

Delete 8

Inorder successor = 10

Replace:

        10
      /    \
     5      12
              \
              15

Then delete the original 10 from the right subtree.*/


class Solution {
public:

    TreeNode* findMin(TreeNode* root) {
        while (root->left)
            root = root->left;
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {

        if (root == NULL)
            return NULL;

        if (key < root->val)
            root->left = deleteNode(root->left, key);

        else if (key > root->val)
            root->right = deleteNode(root->right, key);

        else {

            // Case 1 & 2

            if (root->left == NULL) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }

            if (root->right == NULL) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // Case 3

            TreeNode* successor = findMin(root->right);

            root->val = successor->val;

            root->right = deleteNode(root->right, successor->val);
        }

        return root;
    }
};



/*You can add this to your notes:

> **Time Complexity:** `O(h)` where `h` is the height of the BST. We search for the node, find its inorder successor (if needed), and delete it by traversing only along the tree's height. Hence overall `O(h)` (`O(log n)` for a balanced BST, `O(n)` for a skewed BST).

> **Space Complexity:** `O(h)` due to the recursion stack (`O(log n)` for a balanced BST, `O(n)` for a skewed BST). If implemented iteratively, the extra space would be `O(1)`.
*/