#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value){
        val = value;
        left = right = nullptr;
    }
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
    if(root == nullptr || root == p || root == q)
        return root;

    TreeNode* left = lowestCommonAncestor(root->left,p,q);
    TreeNode* right = lowestCommonAncestor(root->right,p,q);

    if(left == nullptr)
        return right;
    else if(right == nullptr)
        return left;
    else
        return root;
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    TreeNode* p = root->left->left;   // 4
    TreeNode* q = root->left->right;  // 5

    TreeNode* ans = lowestCommonAncestor(root,p,q);

    cout << "Lowest Common Ancestor: " << ans->val << endl;

    return 0;
}

/*
MAIN LOGIC + DATA STRUCTURE WORKFLOW:

1. If root is NULL, p, or q → return root.

2. Recursively search for p and q in the left and right subtrees.

3. left = result from left subtree
   right = result from right subtree

4. If left is NULL → q/p was found on the right,
   so return right.

5. If right is NULL → p/q was found on the left,
   so return left.

6. If BOTH left and right are not NULL,
   one node is on each side, so current root is the LCA.

FLOW:
Root
 ↓
Search Left + Right
 ↓
left / right result
 ↓
Both found → root is LCA
Only one found → return that result
*/