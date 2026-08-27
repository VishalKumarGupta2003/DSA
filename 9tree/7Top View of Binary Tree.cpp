#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int value){
        data = value;
        left = right = nullptr;
    }
};

class Solution {
  public:
    vector<int> topView(Node *root) {
        vector<int> ans;
        if(!root) return ans;

        map<int,int> mpp;
        queue<pair<Node* , int>> q;

        q.push({root,0});

        while(!q.empty()){
            Node* node = q.front().first;
            int line = q.front().second;
            q.pop();

            if(mpp.find(line) == mpp.end())
                mpp[line] = node->data;

            if(node->left != nullptr)
                q.push({node->left , line-1});

            if(node->right != nullptr)
                q.push({node->right , line+1});
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
    vector<int> ans = obj.topView(root);

    cout << "Top View: ";
    for(int x : ans){
        cout << x << " ";
    }

    return 0;
}

/*
MAIN LOGIC + DATA STRUCTURE WORKFLOW:

1. QUEUE:
   Stores {node, vertical line}.
   It is used for BFS/level-order traversal.

   Example:
   {1,0}
   {2,-1}
   {3,1}

2. mpp = map<int,int>:
   Stores:
   vertical line → first node seen on that line

   Example:
   -2 → 4
   -1 → 2
    0 → 1
    1 → 3
    2 → 7

3. Root starts at line 0.
   Left child  → line - 1
   Right child → line + 1

4. BFS visits nodes level by level.
   Therefore, the first node found on a particular
   vertical line is the topmost node.

5. This condition:
   
   if(mpp.find(line) == mpp.end())

   checks whether this vertical line already has a node.
   If it doesn't, store the current node.

6. map automatically sorts the lines from left to right.

7. Finally, take the stored values from mpp and put them
   into ans.

FLOW:
Queue → BFS → vertical line → first node → map → ans

TOP VIEW:
First visible node from each vertical line.
*/