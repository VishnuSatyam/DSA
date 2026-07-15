/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Serialize tree using Level Order Traversal (BFS)
    string serialize(TreeNode* root) {
        if(!root) return "";

        string s = "";
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();

            // Store "X" for NULL nodes to preserve tree structure
            if(curr == NULL)
                s.append("X,");
            else
                s.append(to_string(curr->val) + ',');

            // Push children only for valid nodes
            if(curr != NULL){
                q.push(curr->left);
                q.push(curr->right);
            }
        }

        return s;
    }

    // Deserialize the serialized string back to the original tree
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return NULL;

        // Treat the serialized string as an input stream
        stringstream s(data);
        string str;

        // First value is always the root
        getline(s, str, ',');
        TreeNode* root = new TreeNode(stoi(str));

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();

            // Read left child
            getline(s, str, ',');

            if(str == "X"){
                curr->left = NULL;
            }
            else{
                TreeNode* leftNode = new TreeNode(stoi(str));
                curr->left = leftNode;
                q.push(leftNode);     // Process its children later
            }

            // Read right child
            getline(s, str, ',');

            if(str == "X"){
                curr->right = NULL;
            }
            else{
                TreeNode* rightNode = new TreeNode(stoi(str));
                curr->right = rightNode;
                q.push(rightNode);    // Process its children later
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));


// tc and sc will be O(n)








// basic of stringstream and getline
/*#include <iostream>
#include <sstream>
using namespace std;

int main() {

    string s = "100 200 300";

    stringstream ss(s);

    int x, y, z;

    ss >> x >> y >> z;

    cout << x << endl;
    cout << y << endl;
    cout << z << endl;
}
    
// output:
100
200
300

*/

/*
Problem with >>

Suppose

string s = "Hello World";
stringstream ss(s);

string x;

ss >> x;

Output

Hello

Where did

World go ? 

It wasn't read.

Because

>>

stops at spaces.

*/

// so we got getline

//  getline() reads an entire line until a delimiter.

/*
string s = "Hello World";

stringstream ss(s);

string x;

getline(ss, x);

cout << x;


Output

Hello World
*/

/*
Default delimiter

'\n'

Meaning

read until newline.

But we can change it.

Syntax

getline(stream, variable, delimiter);

*/

/*
string s = "10,20,30,40";

stringstream ss(s);

string token;

while (getline(ss, token, ',')) {

    cout << token << endl;

}

// output

10
20
30
40
*/