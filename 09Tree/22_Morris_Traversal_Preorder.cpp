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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        TreeNode* cur = root;

        while(cur) {

            // Case 1: No left subtree
            if(!cur->left) {
                preorder.push_back(cur->val);
                cur = cur->right;
            }

            // Case 2: Left subtree exists
            else {
                TreeNode* prev = cur->left;

                // Find the rightmost node of left subtree
                while(prev->right && prev->right != cur) {
                    prev = prev->right;
                }

                // First time reaching cur
                if(!prev->right) {

                    // PREORDER:
                    // Process ROOT before going to LEFT
                    preorder.push_back(cur->val);

                    // Create temporary thread
                    prev->right = cur;

                    // Move to left subtree
                    cur = cur->left;
                }

                // Second time reaching cur
                else {
                    // Remove temporary thread
                    prev->right = NULL;

                    // Move to right subtree
                    cur = cur->right;
                }
            }
        }

        return preorder;
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

    vector<int> ans = obj.preorderTraversal(root);

    cout << "Preorder Traversal: ";

    for(int x : ans) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}

/*
===========================================================
MAIN LOGIC
===========================================================

PREORDER:

    ROOT -> LEFT -> RIGHT


1. If cur has NO left child:

       cur

    Process cur immediately:

       preorder.push_back(cur->val);

    Then go right:

       cur = cur->right;


2. If cur HAS a left child:

       cur
       /
      L

    Find the inorder predecessor:

       prev = rightmost node of left subtree


3. FIRST TIME we reach cur:

    prev->right == NULL

    We process cur FIRST because this is PREORDER:

        ROOT -> LEFT -> RIGHT

    So:

        preorder.push_back(cur->val);

    Then create a temporary thread:

        prev->right = cur;

    And move left:

        cur = cur->left;


4. SECOND TIME we reach cur:

    prev->right == cur

    This means the left subtree has been processed.

    Remove the temporary thread:

        prev->right = NULL;

    Then move right:

        cur = cur->right;


===========================================================
IMPORTANT DIFFERENCE FROM MORRIS INORDER
===========================================================

INORDER:

    LEFT -> ROOT -> RIGHT

    Therefore, when the thread is removed:

        preorder.push_back(cur->val);


PREORDER:

    ROOT -> LEFT -> RIGHT

    Therefore, when the thread is CREATED:

        preorder.push_back(cur->val);


So the key difference is:

Morris Inorder:
    Create thread
        ↓
    Go left
        ↓
    Remove thread
        ↓
    Process ROOT


Morris Preorder:
    Create thread
        ↓
    Process ROOT
        ↓
    Go left
        ↓
    Remove thread


===========================================================
OUTPUT
===========================================================

For:

        1
       / \
      2   3
     / \
    4   5
       / \
      6   7

Preorder:

    1 2 4 5 6 7 3


TIME COMPLEXITY  = O(N)
SPACE COMPLEXITY = O(1)
===========================================================
*/