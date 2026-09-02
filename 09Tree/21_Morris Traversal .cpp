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

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        TreeNode* cur = root;

        while(cur) {

            // Case 1: No left subtree
            if(!cur->left) {
                inorder.push_back(cur->val);
                cur = cur->right;
            }

            // Case 2: Left subtree exists
            else {
                // Find the inorder predecessor of cur.
                // It is the rightmost node in cur's left subtree.
                TreeNode* prev = cur->left;

                while(prev->right && prev->right != cur) {
                    prev = prev->right;
                }

                // First time reaching cur:
                // Create a temporary/threaded link
                // from predecessor back to cur.
                if(!prev->right) {
                    prev->right = cur;
                    cur = cur->left;
                }

                // Second time reaching cur:
                // The thread already exists.
                // Remove it and process cur.
                else {
                    prev->right = NULL;
                    inorder.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }

        return inorder;
    }
};

int main() {

    /*
            1
           / \
          2   3
         / \
        4   5
           / \
          6   7
    */

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->left->right->left = new TreeNode(6);
    root->left->right->right = new TreeNode(7);

    Solution obj;

    vector<int> ans = obj.inorderTraversal(root);

    cout << "Inorder Traversal: ";

    for(int x : ans) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}

/*
===========================================================
MAIN LOGIC + DATA STRUCTURE WORKFLOW
===========================================================

This is MORRIS INORDER TRAVERSAL.

Normal inorder:
    LEFT -> ROOT -> RIGHT

The main advantage of Morris Traversal is:

    Time  = O(N)
    Space = O(1)

It does not use:
    - recursion stack
    - explicit stack

-----------------------------------------------------------

1. cur
-----------------------------------------------------------

TreeNode* cur = root;

'cur' represents the current node we are processing.


-----------------------------------------------------------

2. CASE 1: cur has NO LEFT CHILD
-----------------------------------------------------------

if(!cur->left)

Example:

    3
     \
      5

Since there is no left subtree:

    process 3
    move to 5

So:

inorder.push_back(cur->val);
cur = cur->right;


-----------------------------------------------------------

3. CASE 2: cur HAS A LEFT CHILD
-----------------------------------------------------------

Suppose:

        1
       /
      2
       \
        3

For node 1, we cannot immediately process 1.

In inorder:

    LEFT -> ROOT -> RIGHT

So we first need to process the left subtree.


-----------------------------------------------------------

4. FIND INORDER PREDECESSOR
-----------------------------------------------------------

TreeNode* prev = cur->left;

Then:

while(prev->right && prev->right != cur) {
    prev = prev->right;
}

We move to the RIGHTMOST node of cur's
left subtree.

For:

        1
       /
      2
       \
        3

The predecessor of 1 is 3.


-----------------------------------------------------------

5. FIRST TIME: CREATE THREAD
-----------------------------------------------------------

if(!prev->right)

We create:

    prev->right = cur;

Example:

Before:

        1
       /
      2
       \
        3

After:

        1
       /
      2
       \
        3
         \
          1

This temporary link is called a THREAD.

Then:

cur = cur->left;

So we move into the left subtree.


-----------------------------------------------------------

6. WHY CREATE THE THREAD?
-----------------------------------------------------------

Normally, after finishing the left subtree,
we need to come back to the root.

Normally recursion/stack remembers this.

But Morris Traversal does NOT use a stack.

So we create a temporary link:

    predecessor -> current

This allows us to come back to the current node
after finishing its left subtree.


-----------------------------------------------------------

7. SECOND TIME: THREAD ALREADY EXISTS
-----------------------------------------------------------

Eventually we come back to the same node.

Now:

prev->right == cur

So:

else {
    prev->right = NULL;
    inorder.push_back(cur->val);
    cur = cur->right;
}

First:

    prev->right = NULL;

Remove the temporary thread.

Then:

    inorder.push_back(cur->val);

Process the current node.

Finally:

    cur = cur->right;

Move to the right subtree.


-----------------------------------------------------------

8. COMPLETE WORKFLOW
-----------------------------------------------------------

For every cur:

        cur
       /   \
      L     R

If L doesn't exist:

    process cur
    go right


If L exists:

    Find predecessor
            ↓
    Is predecessor->right NULL?
          /       \
        YES       NO
         ↓         ↓
    Create       Remove
    thread       thread
         ↓         ↓
    Go left      Process cur
                   ↓
                Go right


-----------------------------------------------------------

9. IMPORTANT CONDITION
-----------------------------------------------------------

while(prev->right && prev->right != cur)

There are TWO possibilities:

prev->right == NULL

    → We haven't created the thread yet.

prev->right == cur

    → Thread already exists.
    → This is our second visit to cur.


-----------------------------------------------------------

10. WHY O(1) SPACE?
-----------------------------------------------------------

We don't use:

    stack
    recursion

Only a few pointers are used:

    cur
    prev

Therefore auxiliary space:

    O(1)


-----------------------------------------------------------

11. TIME COMPLEXITY
-----------------------------------------------------------

Time = O(N)

Although the inner while loop exists, each edge/
pointer is handled only a constant number of times
during the Morris traversal.

Therefore overall:

    O(N)


FINAL:

Morris Inorder Traversal

    LEFT → ROOT → RIGHT

    Time  = O(N)
    Space = O(1)
*/