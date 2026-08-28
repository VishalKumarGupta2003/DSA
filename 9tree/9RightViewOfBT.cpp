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
    void rightSideRecursion(TreeNode *root,int level,vector<int> &ans){
        if(!root) return;

        if(ans.size() == level)
            ans.push_back(root->val);

        if(root->right)
            rightSideRecursion(root->right,level+1,ans);

        if(root->left)
            rightSideRecursion(root->left,level+1,ans);

        return;
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        rightSideRecursion(root,0,ans);
        return ans;
    }
};

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    Solution obj;
    vector<int> ans = obj.rightSideView(root);

    cout << "Right Side View: ";
    for(int x : ans){
        cout << x << " ";
    }

    return 0;
}

/*
MAIN LOGIC + WORKFLOW:

1. Use recursion with a "level" variable.
   level tells us the current depth of the node.

2. At every level, we need only ONE node for
   the right-side view.

3. Visit the RIGHT child first, then the LEFT child.
   This makes the rightmost node get visited first
   at every level.

4. ans.size() == level means:
   "We have not stored any node for this level yet."

5. Therefore, the first node encountered at each level
   is stored in ans.

6. Once a level already has a value, other nodes at
   that level are ignored.

FLOW:
Root
 ↓
Right first
 ↓
Left second
 ↓
First node at each level → ans

Example:
        1
       / \
      2   3
       \   \
        5   4

Level 0 → 1
Level 1 → 3
Level 2 → 4

Right View = {1, 3, 4}
*/