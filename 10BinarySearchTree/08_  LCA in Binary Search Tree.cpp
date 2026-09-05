#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {

public:

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if(!root) return NULL;

        if(root->val > p->val && root->val > q->val) return lowestCommonAncestor(root->left,p,q);

        if (root->val < p->val && root->val < q->val) return lowestCommonAncestor(root->right,p,q);

        return root;

    }

};

int main() {

    // Creating BST:
    //
    //          6
    //        /   \
    //       2     8
    //      / \   / \
    //     0   4 7   9
    //        / \
    //       3   5

    TreeNode* root = new TreeNode(6);

    root->left = new TreeNode(2);
    root->right = new TreeNode(8);

    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);

    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);

    // Finding LCA of 2 and 8

    TreeNode* p = root->left;
    TreeNode* q = root->right;

    Solution obj;

    TreeNode* ans = obj.lowestCommonAncestor(root, p, q);

    cout << "Lowest Common Ancestor: " << ans->val << endl;

    return 0;
}

// ================= REVISION NOTES =================
//
// CENTRAL LOGIC:
// - Use the BST property to decide which subtree can contain the LCA.
// - If both p and q are smaller than root → move LEFT.
// - If both p and q are greater than root → move RIGHT.
// - Otherwise, they lie on different sides (or root itself is one of them).
//   Therefore, current root is the LCA.
//
// NORMAL FLOWCHART:
//
//              START
//                ↓
//          Is root NULL?
//           /          \
//         YES           NO
//          ↓             ↓
//        Return     Are p,q < root?
//         NULL        /        \
//                   YES         NO
//                    ↓           ↓
//                Go LEFT    Are p,q > root?
//                              /        \
//                            YES         NO
//                             ↓           ↓
//                         Go RIGHT    Return root
//                                         ↓
//                                        END
//
// DATA STRUCTURES:
// - TreeNode:
//   Stores the node's value + pointer to left child + pointer to right child.
// - TreeNode*:
//   Stores the address of a node in the BST.
// - BST:
//   Maintains smaller values on the left and larger values on the right.
//
// COMPLEXITY:
// - Time: O(h), where h = height of BST.
// - Space: O(h) due to recursive function calls.
//
// ==================================================