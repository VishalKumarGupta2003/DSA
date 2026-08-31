#include<bits/stdc++.h>
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

    int findDistance(Node* root, Node* start, map<Node*,Node*> mpp){
        int maxi = 0;
        map<Node*,bool> vis;

        vis[start] = true;

        queue<Node*> q;
        q.push(start);

        while(!q.empty()){
            int size = q.size();
            bool flag = false;

            for(int i = 0; i < size; i++){
                Node* node = q.front();
                q.pop();

                if(node->left && !vis[node->left]){
                    flag = true;
                    q.push(node->left);
                    vis[node->left] = true;
                }

                if(node->right && !vis[node->right]){
                    flag = true;
                    q.push(node->right);
                    vis[node->right] = true;
                }

                if(mpp[node] && !vis[mpp[node]]){
                    flag = true;
                    q.push(mpp[node]);
                    vis[mpp[node]] = true;
                }
            }

            if(flag)
                maxi++;
        }

        return maxi;
    }

    Node* mapParent(Node* root, int target, map<Node*,Node*> &mpp){
        queue<Node*> q;
        q.push(root);

        Node* res = nullptr;

        while(!q.empty()){
            Node* node = q.front();
            q.pop();

            if(node->data == target)
                res = node;

            if(node->left){
                q.push(node->left);
                mpp[node->left] = node;
            }

            if(node->right){
                q.push(node->right);
                mpp[node->right] = node;
            }
        }

        return res;
    }

    int minTime(Node* root, int target) {
        map<Node*,Node*> mpp;

        Node* start = mapParent(root,target,mpp);

        int maxi = findDistance(root,start,mpp);

        return maxi;
    }
};

int main(){
    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(6);
    root->left->right = new Node(9);

    root->right->left = new Node(0);
    root->right->right = new Node(8);

    root->left->right->left = new Node(7);
    root->left->right->right = new Node(4);

    Solution obj;

    int dis = obj.minTime(root,2);

    cout << "The minimum time is: " << dis;

    return 0;
}

/*
MAIN LOGIC + DATA STRUCTURE WORKFLOW:

1. mapParent():
   Creates a mapping:
   
   child → parent

   Example:
   parent[9] = 2
   parent[2] = 1
   parent[3] = 1

   It also finds the node containing the target value.

2. findDistance():
   Start BFS from the target node.

   From every node, we can move in 3 directions:
   LEFT → RIGHT → PARENT

3. vis:
   Stores whether a node has already been visited.
   This prevents going back and forth between child and parent.

4. queue:
   Stores nodes of the current BFS levels.

   Each BFS level represents 1 unit of time.

5. flag:
   Tells whether we were able to reach any new node
   during the current level.

6. maxi:
   Counts how many levels/time units were required
   to reach the farthest burning node.

FLOW:

Tree
 ↓
mapParent()
 ↓
child → parent mapping
 ↓
Find target node
 ↓
BFS from target
 ↓
Move left + right + parent
 ↓
visited prevents repetition
 ↓
Each BFS level = 1 unit time
 ↓
maxi = minimum time to burn entire tree
*/