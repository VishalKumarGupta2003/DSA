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

class Solution {
public:

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> mpp;

        for(int i = 0; i < inorder.size(); i++){
            mpp[inorder[i]] = i;
        }

        TreeNode* root = buildTree(
            preorder, 0, preorder.size()-1,
            inorder, 0, inorder.size()-1,
            mpp
        );

        return root;
    }

    TreeNode* buildTree(
        vector<int>& preorder,
        int preStart,
        int preEnd,
        vector<int>& inorder,
        int inStart,
        int inEnd,
        map<int,int>& mpp
    ){
        if(preStart > preEnd || inStart > inEnd)
            return NULL;

        TreeNode* root = new TreeNode(preorder[preStart]);

        int inRoot = mpp[root->val];

        int inleft = inRoot - inStart;

        root->left = buildTree(
            preorder,
            preStart + 1,
            preStart + inleft,
            inorder,
            inStart,
            inRoot - 1,
            mpp
        );

        root->right = buildTree(
            preorder,
            preStart + inleft + 1,
            preEnd,
            inorder,
            inRoot + 1,
            inEnd,
            mpp
        );

        return root;
    }
};

void printInorder(TreeNode* root){
    if(!root) return;

    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main(){
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};

    Solution obj;

    TreeNode* root = obj.buildTree(preorder,inorder);

    cout << "Constructed Tree Inorder: ";
    printInorder(root);

    return 0;
}

/*
MAIN LOGIC + DATA STRUCTURE WORKFLOW:

1. PREORDER:
   Preorder follows:

       ROOT → LEFT → RIGHT

   Therefore, the first element of preorder is always
   the root of the current subtree.

2. INORDER:
   Inorder follows:

       LEFT → ROOT → RIGHT

   Once we find the root in inorder:
   
       Left side of root  → LEFT SUBTREE
       Right side of root → RIGHT SUBTREE

3. mpp:
   map<int,int> stores:

       node value → its index in inorder

   Example:

       inorder = {9,3,15,20,7}

       mpp[9]  = 0
       mpp[3]  = 1
       mpp[15] = 2
       mpp[20] = 3
       mpp[7]  = 4

   This lets us find the root's position in O(log n)
   instead of searching the inorder array every time.

4. preStart and preEnd:
   Represent the portion of PREORDER currently being used.

5. inStart and inEnd:
   Represent the portion of INORDER currently being used.

6. First element of the current preorder range:

       preorder[preStart]

   becomes the root.

7. Find the root's position in inorder:

       inRoot = mpp[root->val]

8. Calculate the number of nodes in the left subtree:

       inleft = inRoot - inStart

9. LEFT SUBTREE:

   Preorder range:
       preStart + 1 → preStart + inleft

   Inorder range:
       inStart → inRoot - 1

10. RIGHT SUBTREE:

    Preorder range:
        preStart + inleft + 1 → preEnd

    Inorder range:
        inRoot + 1 → inEnd

11. Recursively repeat the same process for both
    left and right subtrees.

12. BASE CONDITION:

       if(preStart > preEnd || inStart > inEnd)

    means there are no elements left to construct
    the current subtree, so return NULL.


EXAMPLE:

Preorder = {3,9,20,15,7}
Inorder  = {9,3,15,20,7}

First:
    preorder[0] = 3
    → 3 is root

In inorder:

    {9, 3, 15, 20, 7}
       ↑
      root

Left of 3:
    {9}

Right of 3:
    {15,20,7}

The same process is recursively applied to both sides.


FLOW:

Preorder → first element = ROOT
                  ↓
         Find ROOT in inorder
                  ↓
       ┌──────────┴──────────┐
       ↓                     ↓
 Left part of inorder   Right part of inorder
       ↓                     ↓
 Left subtree           Right subtree
       ↓                     ↓
       └────── Recursion ────┘
*/