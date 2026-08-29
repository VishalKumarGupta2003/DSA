#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value){
        val=value;
        left=right=nullptr;
    }
};

bool symmetric(TreeNode* root1,TreeNode* root2){
    if(!(root1) || !(root2)) return root1 == root2;
    if(root1->val != root2->val) return false;
    return symmetric(root1->left,root2->right) && symmetric(root2->left,root1->right);


}
bool isSymmetric(TreeNode* root) {
    
    return symmetric(root->left,root->right);

}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    cout<<boolalpha<<((isSymmetric(root)));
    return 0;
}