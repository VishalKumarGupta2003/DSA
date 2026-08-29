#include <bits/stdc++.h>
using namespace std;

// Node Structure
class Node {
public:
    int data;
    Node* left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
public:
    bool isLeaf(Node* root) {
        return root->left == nullptr && root->right == nullptr;
    }

    void addLeftBoundary(Node* root,vector<int> &ans){
        Node* cur = root->left;
        while(cur){
            if(!isLeaf(cur)) ans.push_back(cur->data);
            if(cur->left) cur=cur->left;
            else cur=cur->right;
        }
        return ;
    }

    void addLeaves(Node* root,vector<int> &ans){
        if(isLeaf(root)) ans.push_back(root->data);
        if(root->left) addLeaves(root->left,ans);
        if(root->right) addLeaves(root->right,ans);
    }

    void addRightBoundary(Node* root,vector<int> &ans){
        Node* cur = root->right;
        vector<int> temp;
        while(cur){
            if(!isLeaf(cur)) temp.push_back(cur->data);
            if(cur->right) cur=cur->right;
            else cur=cur->left;
        }
        
        for(int i=temp.size()-1;i>=0;i--){
            ans.push_back(temp[i]);
        }
        return ;
    }
    
    vector<int> boundaryTraversal(Node *root) {
        vector<int> ans;
        if(!root) return ans;
        if(!isLeaf(root)) ans.push_back(root->data);
        addLeftBoundary(root,ans);
        addLeaves(root,ans);
        addRightBoundary(root,ans);
        return ans;
    }
};

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    Solution obj;
    vector<int> ans = obj.boundaryTraversal(root);

    for(int x : ans)
        cout << x << " ";

    return 0;
}

/*
MAIN LOGIC:
1. First add the root, if it is not a leaf.
2. Add the left boundary from top to bottom, excluding leaves.
3. Add all leaf nodes from left to right.
4. Add the right boundary from bottom to top, excluding leaves.
5. Right boundary is stored separately and then reversed.
6. This avoids adding any leaf node twice.

ORDER:
Root → Left Boundary → Leaves → Right Boundary (reverse)
*/