#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value){
        val = value;
        left = right= nullptr;
    }
};
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int size = inorder.size();
        map<int, int> mpp;
        for(int i=0;i<size;i++){
            mpp[inorder[i]] = i;
        }
        TreeNode* root = buildTree(inorder,0,size-1,postorder,0,size-1,mpp);
        return root;
    }
    TreeNode* buildTree(vector<int> &inorder,int instart,int inend,vector<int> postorder,int poststart,int postend, map<int,int> &mpp){
        if(instart > inend || poststart >postend) return NULL;
        TreeNode* root = new TreeNode(postorder[postend]);
        int inroot = mpp[root->val];
        int inleft = inroot-instart;
        root->left = buildTree(inorder,instart,inroot-1,postorder,poststart,poststart+inleft-1,mpp);
        root->right = buildTree(inorder,inroot+1,inend,postorder,poststart+inleft,postend-1,mpp);
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
    vector<int> inorder = {9,3,15,20,7};
    vector<int> postorder = {9,15,7,20,3};

    Solution obj;

    TreeNode* root = obj.buildTree(inorder,postorder);

    cout << "Constructed Tree Inorder: ";
    printInorder(root);

    return 0;
}