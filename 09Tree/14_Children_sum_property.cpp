#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int value){
        val = value;
        left = right= nullptr;
    }
};

void changeTree(Node* root){
    if(!root) return;
    int child = 0;
    if(root->left) child += root->left->val;
    if(root->right) child += root->right->val;
    
    if(child >= root->val) root->val = child;
    else{
        if(root->left) root->left->val = root->val;
        else if(root -> right) root->right->val = root->val;
    }

    changeTree(root->left);
    changeTree(root->right);

    int total = 0;
    if(root->left) total += root->left->val;
    if(root->right) total += root->right->val;
    if(root->left or root->right) root->val =total;
    return;
}

void levelOrder(Node* root) {
    if (root == nullptr)
        return; // Empty tree has nothing to traverse
    queue<Node*> q;
    q.push(root); // Start with the root
    while (!q.empty()) {
        Node* node = q.front(); // Get the front node
        q.pop(); // Remove it from the queue
        cout << node->val << " ,"; // Visit current node
        if (node->left != nullptr) q.push(node->left); // Add left child
        if (node->right != nullptr) q.push(node->right); // Add right child
    }
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    cout<<"Before Modification :- ";
    levelOrder(root);
    cout<<endl;
    changeTree(root);
    cout<<"After Modification :- ";
    levelOrder(root);
    return 0;
}