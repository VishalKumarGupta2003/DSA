#include <bits/stdc++.h>
using namespace std;


// struct Vishal {
//     int mulya;
//     Vishal* left;
//     Vishal* right;

//     Vishal(int value) {
//         mulya = value;
//         left = nullptr;
//         right = nullptr;
//     }
// };

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value){
        val=value;
        left=right=nullptr;
    }
};

// 1)Maximum Depth in Binary Tree
int maxDepth(TreeNode* root){
    if(root == nullptr) return 0;
    int lh=maxDepth(root->left);
    int rh=maxDepth(root-> right);
    int cnt = 1+ max(lh,rh);
    return cnt;
}

// 2)Check for Balanced Binary Tree 
// class solution {
// public:
//     // Main Logic: Find the height of each subtree while checking balance at the same time.
//     // If any subtree is unbalanced, return -1 immediately. Otherwise return its height.
//     // Height of current node = 1 + max(left height, right height).
//     // Finally, if checkbalanced(root) returns -1, tree is unbalanced; otherwise balanced.
//     bool isBalanced(TreeNode* root) {
//         return checkbalanced(root) != -1; // -1 means an unbalanced subtree was found
//     }
//     int checkbalanced(TreeNode* root){
//         if(root == nullptr) return 0; // Height of an empty tree is 0
//         int lh=checkbalanced(root->left); // Get left subtree height
//         if(lh == -1) return -1; // Left subtree is unbalanced
//         int rh = checkbalanced(root->right); // Get right subtree height
//         if(rh == -1) return -1; // Right subtree is unbalanced
//         if(abs(rh-lh) > 1) return -1; // Current node is unbalanced
//         return 1+max(lh,rh); // Return height of current subtree
//     }
// };

// 3) DIAMETER OF BT => LONGEST B/W TWO NODES
//                   =>   PATH DOES NOT NEED TO PASS VIA ROOT
// Main Logic: Calculate height and diameter together in one traversal.
// For every node, the longest path passing through it = left height + right height.
// Keep updating the maximum diameter and return the height of the current subtree.
// int height(TreeNode* root, int& diameter){
//     if(root == nullptr) return 0; // Height of empty tree is 0
//     int lh = height(root->left,diameter); // Get left subtree height
//     int rh = height(root->right , diameter); // Get right subtree height
//     diameter=max(diameter,lh+rh); // Diameter through current node
//     return 1+max(lh,rh); // Return height of current subtree
// }
// int diameterOfBinaryTree(TreeNode* root) {
//     int diameter = 0;
//     height(root,diameter); // Calculate height and update diameter
//     return diameter; // Diameter is measured in number of edges
// }

// 4) Maximum Path Sum in Binary Tree
// Main Logic: For every node, calculate the maximum path sum that can be extended
// upward to its parent. Ignore negative subtree sums using max(0,...), because they
// would decrease the path sum. The best path passing through the current node is
// left + root + right, so update maxi with it. Return root + max(left,right) because
// a path going upward can use only one side of the current node.
// int maxSum(TreeNode* root,int &maxi){
//     if(root == nullptr) return 0; // Empty subtree contributes 0
//     int left = max(0,maxSum(root->left,maxi)); // Ignore negative left path
//     int right = max(0,maxSum(root->right,maxi)); // Ignore negative right path
//     maxi=max(maxi,left+right+root->val); // Best path passing through current node
//     return (max(left,right))+root->val; // Return best single-side path to parent
// }
// int maxPathSum(TreeNode* root) {
//     int maxi=INT_MIN;
//     maxSum(root,maxi); // Calculate path sums and update maximum
//     return maxi; // Maximum path sum
// }

int main(){
    TreeNode* root= new TreeNode(1);
    //Vishal* root = new Vishal(10);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->right=new TreeNode(5);

    //cout<<maxDepth(root);

    // maxPathSum(root);

    

    return 0;
    
}