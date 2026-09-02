#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = right = nullptr;
    }
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";

        string str = "";
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if(!node)
                str.append("#,");
            else
                str.append(to_string(node->val) + ",");

            if(node) {
                q.push(node->left);
                q.push(node->right);
            }
        }

        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0)
            return NULL;

        // stringstream treats the string 'data' like an input stream.
        //
        // Example:
        // data = "1,2,3,#,#,4,5,#,#,#,#,"
        //
        // stringstream allows us to read this string
        // one value at a time.
        stringstream s(data);

        string str;

        // getline() reads from stream 's' until ',' is found.
        //
        // First call:
        // data = "1,2,3,#,#,..."
        // str  = "1"
        //
        // Second call:
        // str = "2"
        //
        // Third call:
        // str = "3"
        //
        // So getline(s,str,',') extracts one value at a time.
        getline(s, str, ',');

        // getline() gives us a string.
        //
        // Example:
        // str = "10"
        //
        // stoi(str) converts:
        // "10" -> 10
        //
        // TreeNode constructor needs an int,
        // so:
        // new TreeNode(stoi(str))
        //
        // becomes:
        // new TreeNode(10)
        TreeNode* node = new TreeNode(stoi(str));

        queue<TreeNode*> q;
        q.push(node);

        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            // Read left child
            getline(s, str, ',');

            if(str == "#") {
                node->left = NULL;
            }
            else {
                TreeNode* leftNode = new TreeNode(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }

            // Read right child
            getline(s, str, ',');

            if(str == "#") {
                node->right = NULL;
            }
            else {
                TreeNode* rightNode = new TreeNode(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
        }

        return node;
    }
};

// Function to print tree using inorder traversal
void inorder(TreeNode* root) {
    if(!root) return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {

    /*
                1
               / \
              2   3
             / \   \
            4   5   6
               /
              7
    */

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->right = new TreeNode(6);

    root->left->right->left = new TreeNode(7);

    Codec obj;

    // Serialize the tree
    string data = obj.serialize(root);

    cout << "Serialized Tree: " << data << endl;

    // Deserialize the string back into a tree
    TreeNode* newRoot = obj.deserialize(data);

    cout << "Inorder of Deserialized Tree: ";
    inorder(newRoot);
    cout << endl;

    return 0;
}

/*
===========================================================
MAIN LOGIC + DATA STRUCTURE WORKFLOW
===========================================================

1. SERIALIZATION
----------------

We use a QUEUE for BFS traversal.

Tree:

        1
       / \
      2   3
     / \   \
    4   5   6
       /
      7

The tree is visited level by level.

For every node:
    - If node exists -> store its value.
    - If node is NULL -> store "#".

Example output:

1,2,3,4,5,#,6,#,#,7,#,#,#,

The "#" is important because it tells us that
a particular child is NULL.


2. DESERIALIZATION
------------------

We have the serialized string:

1,2,3,4,5,#,6,#,#,7,#,#,#,

We need to convert this string back into a tree.


3. stringstream
---------------

stringstream s(data);

It converts the string into something that can be
read like an input stream.

Similar to:

cin >> x;

Here we use:

getline(s, str, ',');

to read values from the string.


4. getline()
------------

getline(s, str, ',');

Means:

Read characters from 's'
until ',' is found
and store them in 'str'.

Example:

data = "1,2,3,#,#,"

First:
    str = "1"

Second:
    str = "2"

Third:
    str = "3"

Fourth:
    str = "#"


5. stoi()
---------

stoi = string to integer

Example:

str = "25"

stoi(str) = 25

Why do we need this?

Because getline() gives us a STRING:

"25"

But TreeNode expects an INTEGER:

25

Therefore:

new TreeNode(stoi(str));

means:

"25"
 ↓
stoi()
 ↓
25
 ↓
new TreeNode(25)


6. QUEUE DURING DESERIALIZATION
-------------------------------

The queue stores nodes whose children still
need to be created.

Initially:

Queue = [1]

Process 1:

Create 2 and 3.

Queue = [2, 3]

Process 2:

Create 4 and 5.

Queue = [3, 4, 5]

Process 3:

Create NULL and 6.

Queue = [4, 5, 6]

And so on.


7. COMPLETE FLOW
----------------

SERIALIZE:

Original Tree
     ↓
BFS using Queue
     ↓
Values + "#" for NULL
     ↓
String


DESERIALIZE:

String
   ↓
stringstream
   ↓
getline()
   ↓
String value
   ↓
stoi()
   ↓
Integer
   ↓
Create TreeNode
   ↓
Queue
   ↓
Reconstruct Tree


8. IMPORTANT FUNCTIONS
----------------------

serialize(root)

    Tree → String


deserialize(data)

    String → Tree


getline(s, str, ',')

    Extracts one comma-separated value.


stoi(str)

    Converts string → integer.


new TreeNode(stoi(str))

    Converts the extracted string into an integer
    and creates a new tree node.
*/