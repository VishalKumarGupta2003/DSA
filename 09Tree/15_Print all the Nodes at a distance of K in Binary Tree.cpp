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
    void markParent(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &parentTrack){
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* cur = q.front();
            q.pop();

            if(cur->left){
                q.push(cur->left);
                parentTrack[cur->left] = cur;
            }

            if(cur->right){
                q.push(cur->right);
                parentTrack[cur->right] = cur;
            }
        }
    }

    vector<int> distanceK(TreeNode* root,TreeNode* target,int k){
        unordered_map<TreeNode*,TreeNode*> parentTrack;

        markParent(root,parentTrack);

        unordered_map<TreeNode*,bool> visited;

        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;

        int level = 0;

        while(!q.empty()){
            int size = q.size();

            if(level++ == k)
                break;

            for(int i = 0;i < size;i++){
                TreeNode* node = q.front();
                q.pop();

                if(node->left && !visited[node->left]){
                    q.push(node->left);
                    visited[node->left] = true;
                }

                if(node->right && !visited[node->right]){
                    q.push(node->right);
                    visited[node->right] = true;
                }

                if(parentTrack[node] && !visited[parentTrack[node]]){
                    q.push(parentTrack[node]);
                    visited[parentTrack[node]] = true;
                }
            }
        }

        vector<int> ans;

        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }
};

int main(){
    TreeNode* root = new TreeNode(3);

    root->left = new TreeNode(5);
    root->right = new TreeNode(1);

    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);

    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    TreeNode* target = root->left;  // Node 5
    int k = 2;

    Solution obj;

    vector<int> ans = obj.distanceK(root,target,k);

    cout << "Nodes at distance " << k << ": ";

    for(int x : ans){
        cout << x << " ";
    }

    return 0;
}

/*
MAIN LOGIC + DATA STRUCTURE WORKFLOW:

1. parentTrack:
   Stores:
   child → parent

   Example:
   parentTrack[5] = 3
   parentTrack[1] = 3
   parentTrack[6] = 5

   This allows us to move UP the tree.

2. First mark all parent relationships using BFS.

3. visited:
   Keeps track of nodes already visited.
   It prevents moving in a cycle:
   child → parent → child → parent...

4. queue:
   Starts from target and performs BFS.

   From every node we can move in 3 directions:
   LEFT child
   RIGHT child
   PARENT

5. level:
   Keeps track of distance from the target.

   target = distance 0
   next level = distance 1
   next level = distance 2
   ...

6. When level == k, the queue contains exactly the
   nodes at distance k.

FLOW:

Tree
 ↓
parentTrack (child → parent)
 ↓
Start BFS from target
 ↓
Move: left + right + parent
 ↓
visited prevents repetition
 ↓
Reach distance k
 ↓
queue contains required nodes
 ↓
ans
*/