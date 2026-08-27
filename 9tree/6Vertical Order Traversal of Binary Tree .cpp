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

vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(root == nullptr) return {};
        map<int ,map<int,multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int,int>>> todo;
        todo.push({root,{0,0}});
        while(!todo.empty()){
            auto p = todo.front();
            todo.pop();
            TreeNode* node = p.first;
            int x=p.second.first,y=p.second.second;
            nodes[x][y].insert(node->val);
            if(node->left) todo.push({node->left,{x-1,y+1}});
            if(node->right) todo.push({node->right,{x+1,y+1}});
        }
        vector<vector<int>> ans;
        for(auto p: nodes){
            vector<int> col;
            for(auto q : p.second){
                col.insert(col.end(),q.second.begin(),q.second.end()); //`col.insert(col.end(), q.second.begin(), q.second.end());` **copies all elements from `q.second` (the current level's multiset) and appends them to the end of `col` (the current vertical column).**

            }
            ans.push_back(col);
        }
        return ans;
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    vector<vector<int>> ans = verticalTraversal(root);

    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
MAIN LOGIC + DATA STRUCTURE WORKFLOW:

1. QUEUE:
   Stores {node, {x,y}}.
   It is used for BFS traversal.
   
   Example:
   {1,{0,0}}
   {2,{-1,1}}
   {3,{1,1}}

2. nodes = map<int,map<int,multiset<int>>>:
   
   It stores:
   x-coordinate → y-coordinate → node values
   
   Example:
   nodes[-1][1] = {2}
   nodes[0][0]  = {1}
   nodes[0][2]  = {5}
   nodes[1][1]  = {3}
   
   OUTER MAP:
   Stores x-coordinate (vertical column).
   Keeps columns sorted from left to right.

   INNER MAP:
   Stores y-coordinate (level).
   Keeps nodes sorted from top to bottom.

   MULTISET:
   Stores values having the same x and y.
   Keeps those values sorted and allows duplicates.

3. COORDINATES:
   Root = (0,0)
   Left child  = (x-1,y+1)
   Right child = (x+1,y+1)

4. After BFS, nodes contains the complete tree
   arranged according to vertical column and level.

5. We traverse nodes:
   Outer map → columns left to right
   Inner map → levels top to bottom
   Multiset → values in sorted order

6. Each column is stored in col,
   and every col is finally stored in ans.

FLOW:
Tree
 ↓
Queue {node,x,y}
 ↓
nodes[x][y]
 ↓
Sorted columns + levels + values
 ↓
col
 ↓
ans
*/