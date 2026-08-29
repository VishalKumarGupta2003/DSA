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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;

        int ans = 0;
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});

        while(!q.empty()){
            long long mmin = q.front().second;
            int size = q.size();
            int first,last;

            for(int i = 0; i < size; i++){
                long long cur = q.front().second - mmin;
                TreeNode* node = q.front().first;
                q.pop();

                if(i == 0) first = cur;
                if(i == size-1) last = cur;

                if(node->left)
                    q.push({node->left,2*cur+1});

                if(node->right)
                    q.push({node->right,2*cur+2});
            }

            ans = max(ans,last-first+1);
        }

        return ans;
    }
};

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    Solution obj;

    cout << "Maximum Width: "
         << obj.widthOfBinaryTree(root) << endl;

    return 0;
}

/*
MAIN LOGIC + DATA STRUCTURE WORKFLOW:

1. QUEUE:
   Stores {node, index}.
   BFS processes the tree level by level.

2. INDEX:
   Treat the tree like a complete binary tree:
   
   Left child  → 2*index + 1
   Right child → 2*index + 2

3. mmin:
   Stores the index of the first node of the current level.
   We subtract mmin from every index to keep numbers small.

4. first:
   Index of the first node in the current level.

5. last:
   Index of the last node in the current level.

6. WIDTH:
   last - first + 1

   This counts the positions between the first and last
   node, including NULL positions.

7. ans stores the maximum width found among all levels.

FLOW:
Queue → BFS level
      ↓
Assign indexes
      ↓
first + last index
      ↓
width = last - first + 1
      ↓
maximum width → ans
*/