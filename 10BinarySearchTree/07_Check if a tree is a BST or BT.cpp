#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LLONG_MIN, LLONG_MAX);
    }

    bool isValidBST(TreeNode* root, long long minVal, long long maxVal) {
        if(!root) return true;

        if(minVal >= root->val || maxVal <= root->val)
            return false;

        return isValidBST(root->left, minVal, root->val) &&
               isValidBST(root->right, root->val, maxVal);
    }
};

int main() {

    /*
            10
           /  \
          5    15
              /  \
             12   20
    */

    TreeNode* root = new TreeNode(10);

    root->left = new TreeNode(5);
    root->right = new TreeNode(15);

    root->right->left = new TreeNode(12);
    root->right->right = new TreeNode(20);

    Solution obj;

    if(obj.isValidBST(root))
        cout << "Valid BST" << endl;
    else
        cout << "Not a Valid BST" << endl;

    return 0;
}

/*
===========================================================
MAIN LOGIC
===========================================================

The idea is to give every node a valid RANGE.

For the root:

    minVal = LLONG_MIN
    maxVal = LLONG_MAX

So root can contain any int value.

For every node:

    minVal < root->val < maxVal

If this condition is violated, return false.


===========================================================
HOW RANGE CHANGES
===========================================================

For a node:

        root
        /  \
       L    R

LEFT SUBTREE:

Every node must be smaller than root->val.

So:

    isValidBST(root->left, minVal, root->val)


RIGHT SUBTREE:

Every node must be greater than root->val.

So:

    isValidBST(root->right, root->val, maxVal)


Example:

        10
       /  \
      5    15
          /  \
         12   20


For 5:

    -∞ < 5 < 10


For 15:

    10 < 15 < +∞


For 12:

    10 < 12 < 15


For 20:

    15 < 20 < +∞


===========================================================
WHY RANGE IS NECESSARY
===========================================================

Consider:

        10
       /  \
      5    15
          /
         8

8 is smaller than 15, so checking only its parent
would make it look valid.

But 8 is in the RIGHT subtree of 10.

Therefore:

    8 must be greater than 10.

Its valid range is:

    10 < 8 < 15

which is false.

Therefore the tree is NOT a BST.


===========================================================
WHY LONG LONG?
===========================================================

We use:

    LLONG_MIN
    LLONG_MAX

instead of:

    INT_MIN
    INT_MAX

because TreeNode->val is an int and can itself contain
INT_MIN or INT_MAX.

Using long long gives us a range outside the possible
int values.

Therefore:

    LLONG_MIN < int value < LLONG_MAX


===========================================================
BASE CASE
===========================================================

if(!root) return true;

An empty tree is considered a valid BST.

Also, when we reach NULL while recursively traversing,
there is no violation, so we return true.


===========================================================
CONDITION
===========================================================

if(minVal >= root->val || maxVal <= root->val)
    return false;

This means:

    root->val must satisfy

    minVal < root->val < maxVal

The inequalities are STRICT.

Therefore duplicate values are not allowed in this
BST definition.


===========================================================
WORKFLOW
===========================================================

Start at root
     ↓
Give root range (-∞, +∞)
     ↓
Check root
     ↓
     ├── Left → (minVal, root->val)
     │
     └── Right → (root->val, maxVal)
              ↓
         Check every node
              ↓
     Any violation?
       /          \
     YES           NO
      ↓             ↓
   false       Continue
                  ↓
             All nodes valid
                  ↓
                true


===========================================================
COMPLEXITY
===========================================================

Time Complexity:

    O(N)

Every node is visited once.

Space Complexity:

    O(H)

Because of recursion stack.

For a balanced tree:

    O(log N)

For a skewed tree:

    O(N)


===========================================================
*/