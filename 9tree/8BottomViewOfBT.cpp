#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = nullptr;
    }
};

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        vector<int> ans;
        if(!root) return ans;

        map<int,int> mpp;
        queue<pair<Node* , int>> q;

        q.push({root,0});

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            Node* node = it.first;
            int line = it.second;

            mpp[line] = node->data;

            if(node->left)
                q.push({node->left,line-1});

            if(node->right)
                q.push({node->right,line+1});
        }

        for(auto it:mpp){
            ans.push_back(it.second);
        }

        return ans;
    }
};

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution obj;
    vector<int> ans = obj.bottomView(root);

    cout << "Bottom View: ";
    for(int x : ans){
        cout << x << " ";
    }

    return 0;
}

/*
MAIN LOGIC + DATA STRUCTURE WORKFLOW:

1. QUEUE:
   Stores {node, vertical line}.
   Used for BFS traversal.

2. MAP:
   map<int,int> mpp stores:
   vertical line → node value

3. ROOT starts at line 0.
   Left child  → line - 1
   Right child → line + 1

4. Whenever a node is visited:
   mpp[line] = node->data

   If another node is found on the same line,
   it REPLACES the previous value.

5. Since BFS goes level by level, deeper nodes are
   processed later and replace the upper nodes.
   Therefore, the last node stored on each line
   becomes the bottom-view node.

6. map automatically sorts the vertical lines from
   left to right.

FLOW:
Queue → BFS → line → overwrite map[line] → ans

TOP VIEW vs BOTTOM VIEW:
Top View    → store FIRST node on each line
Bottom View → store LAST node on each line
*/