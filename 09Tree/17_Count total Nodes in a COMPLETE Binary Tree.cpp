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

    int countNodes(TreeNode* root) {
        if(!root) return 0;

        int lh = leftHeight(root);
        int rh = rightHeight(root);

        if(lh == rh)
            return (1 << lh) - 1;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    int leftHeight(TreeNode* root){
        int h = 1;

        TreeNode* node = root->left;

        while(node){
            h++;
            node = node->left;
        }

        return h;
    }

    int rightHeight(TreeNode* root){
        int h = 1;

        TreeNode* node = root->right;

        while(node){
            h++;
            node = node->right;
        }

        return h;
    }
};

int main(){
    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution obj;

    cout << "Number of nodes: " << obj.countNodes(root);

    return 0;
}

/*
MAIN LOGIC + DATA STRUCTURE WORKFLOW:

1. countNodes() is used to count the total number of nodes.

2. For every subtree, calculate:
   
   lh = height of the leftmost path
   rh = height of the rightmost path

3. If:
   
   lh == rh

   then the subtree is a COMPLETE/PERFECT subtree
   for which this height-based formula can be used:

       Total nodes = 2^h - 1

   In code:

       (1 << lh) - 1

   Here:
       1 << lh  means 2^lh

4. If lh != rh:
   The subtree is not perfect, so recursively count:

       1 + left subtree nodes + right subtree nodes

5. leftHeight():
   Starts from root->left and continuously moves left.

6. rightHeight():
   Starts from root->right and continuously moves right.

7. No special data structure is used.
   Only pointers are used to travel down the leftmost
   and rightmost paths.

FLOW:

countNodes(root)
       ↓
calculate left height + right height
       ↓
   lh == rh ?
    /       \
  YES        NO
   ↓          ↓
2^h - 1    1 + count(left) + count(right)

IMPORTANT:
This approach is efficient specifically because it uses
the properties of a COMPLETE binary tree instead of
visiting every node.
*/