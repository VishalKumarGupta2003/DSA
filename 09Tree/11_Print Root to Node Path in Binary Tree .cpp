#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left ;
    Node* right;
    Node(int value){
        data = value;;
        left = right = nullptr;
    }
};

bool isLeaf(Node* root) {
        return root->left == nullptr && root->right == nullptr;
    }
    void addLeaves(Node* root,vector<int> &addleaves){
        if(isLeaf(root)) addleaves.push_back(root->data);
        if(root->left) addLeaves(root->left,addleaves);
        if(root->right) addLeaves(root->right,addleaves);
    }
    bool getPath(Node* root,vector<int> &ans,int x){
        if(!root) return false;
        ans.push_back(root->data);
        if(root->data == x) return true;
        if(getPath(root->left,ans,x) || getPath(root->right,ans,x)) return true;
        ans.pop_back();
        return false;
    }
    vector<vector<int>> paths(Node* root) {
        // code here
        vector<vector<int>> ans;
        if(!root) return ans;
        vector<int> addleaves;
        addLeaves(root,addleaves);
        for(int i=0;i<addleaves.size();i++){
            vector<int> temp;
            getPath(root,temp,addleaves[i]);
            ans.push_back(temp);
        }
        return ans;
    }


vector<int> printPath(Node* root,int x){
    vector<int> ans;
    if(!root) return ans;
    getPath(root,ans,x);
    return ans;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    vector<vector<int>> ans = paths(root);

    for(auto &path : ans){
        for(auto &node : path){
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}


/*
MAIN LOGIC + DATA STRUCTURE WORKFLOW:

1. addLeaves():
   Finds all leaf nodes and stores their values in addleaves.

2. getPath():
   Finds the path from root to a given node x.
   - Add current node to ans.
   - If x is found, return true.
   - Recursively search left and right.
   - If node is not on the path, remove it using pop_back().

3. paths():
   First get all leaf nodes.
   Then find the root-to-leaf path for every leaf
   and store each path inside ans.

DATA STRUCTURES:

addleaves → stores values of all leaf nodes.

temp → stores ONE root-to-leaf path.

ans → stores ALL root-to-leaf paths.

FLOW:

Tree
 ↓
Find leaf nodes → addleaves
 ↓
Take one leaf at a time
 ↓
getPath(root, leaf)
 ↓
temp = root → leaf path
 ↓
ans.push_back(temp)
 ↓
All root-to-leaf paths → ans

IMPORTANT:
getPath() uses backtracking:
push_back() → explore → pop_back() if path is wrong.
*/