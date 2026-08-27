#include <bits/stdc++.h>
using namespace std;


struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// 1) BFS 
// Main Logic: Preorder traversal follows Root -> Left -> Right.
// First process the current node, then recursively visit its left subtree,
// and finally recursively visit its right subtree.
// void preorder(Node* root) {
//     if (root == nullptr)
//         return; // Stop when there is no node
//     cout << root->data << " "; // Visit root first
//     preorder(root->left); // Traverse left subtree
//     preorder(root->right); // Traverse right subtree
// }

// 2) DFS OR LEVEL ORDER TRAVERSAL
// Main Logic: Level order traversal uses a queue and visits the tree level by level.
// First push the root. For every node, remove it from the front, process it, then
// push its left and right children. The queue ensures nodes are processed level-wise.
// void levelOrder(Node* root) {
//     if (root == nullptr)
//         return; // Empty tree has nothing to traverse
//     queue<Node*> q;
//     q.push(root); // Start with the root
//     while (!q.empty()) {
//         Node* node = q.front(); // Get the front node
//         q.pop(); // Remove it from the queue
//         cout << node->data << " ,"; // Visit current node
//         if (node->left != nullptr) q.push(node->left); // Add left child
//         if (node->right != nullptr) q.push(node->right); // Add right child
//     }
// }

//3) Iterative Preorder Traversal in Binary Tree USING STACK
// Main Logic: Use a stack to simulate recursive preorder traversal.
// Preorder is Root -> Left -> Right. Since stack follows LIFO, push the right
// child first and left child second, so the left child is processed first.
// void preorderStack(Node* root){
//     if(root == nullptr) return; // Empty tree
//     stack<Node*> st;
//     st.push(root); // Start with root
//     while(! st.empty()){
//         root = st.top(); // Get the top node
//         st.pop(); // Remove it from stack
//         cout<<root-> data << " "; // Process root
//         if(root->right != nullptr){
//             st.push(root->right); // Push right first
//         }
//         if(root->left !=nullptr){
//             st.push(root->left); // Push left after right so left comes out first
//         }
//     }
// }

// 4) Iterative Inorder Traversal in Binary Tree using STACK
//METHOD 1:- THIS WILL EXCEED TIME LIMIT
// vector<int> inorderTraversal(TreeNode* root) {
//         if(root == nullptr){
//             return {};
//         }
//         vector<int> in;
//         stack<TreeNode*> st;
//         st.push(root);
//         while(!st.empty()){
//             root=st.top();
//             if(root->left != nullptr){
//                 st.push(root->left);
//             }
//             else{
//                 in.push_back(root->val);
//                 st.pop();
//                 if(root->right != nullptr){
//                     st.push(root->right);
//                 }
//             }
//         }
//         return in;
//     }
//METHOD 2:-
// Main Logic: Use a stack to simulate recursive inorder traversal.
// Inorder is Left -> Root -> Right. Keep moving left and push every node into
// the stack. When no left node remains, process the top node, then move to its right subtree.
// void inorderStack(Node* root){
//     stack<Node*> st;
//     Node* node = root;
//     while (true){
//         if(node != nullptr){
//             st.push(node); // Store node and move left
//             node=node->left;
//         }
//         else{
//             if(st.empty() == true) break; // Traversal is complete
//             node= st.top(); // Get the last unprocessed node
//             st.pop(); // Remove it from stack
//             cout<< node->data << " "; // Process node
//             node = node->right; // Move to right subtree
//         }
//     }
// }

// 5) Iterative Postorder Traversal using 2 Stack
// void postorder2Stack(Node * root){
//     if(root == nullptr) return;
//     stack<Node*> st1,st2;
//     st1.push(root);
//     while(! st1.empty()){
//         root=st1.top();
//         st1.pop();
//         st2.push(root);
//         if(root-> left != nullptr){
//             st1.push(root->left);
//         }
//         if(root->right != nullptr){
//             st1.push(root->right);
//         }
//     }
//     while(!st2.empty()){
//         root=st2.top();
//         st2.pop();
//         cout<< root->data<<" ";
//     }
// }

// 6) Iterative Postorder Traversal using 1 Stack
// Main Logic: Use one stack to simulate postorder traversal (Left -> Right -> Root).
// Keep moving left and pushing nodes. When there is no left child, check the right
// child. If the right subtree is absent or already processed, process the node.
// The while loop handles consecutive nodes whose right subtrees are already done.
// void postorder2Stack(Node* root){
//     if(root == nullptr) return ;
//     Node* cur= root;
//     stack<Node*> st;
//     while(cur != nullptr || !st.empty()){
//         if(cur!= nullptr ){
//             st.push(cur);
//             cur=cur->left;
//         }
//         else{
//             Node* temp= st.top()->right; // Check the right subtree
//             if(temp == nullptr){
//                 temp=st.top();
//                 st.pop();
//                 cout<<temp->data<<" "; // Process node after left and right
//                 while(!st.empty() && temp == st.top()->right){
//                     temp=st.top();
//                     st.pop();
//                     cout<< temp->data<<" "; // Process ancestors whose right subtree is done
//                 }
//             }
//             else cur=temp; // Traverse the right subtree
//         }
//     }
//     return ;
// }

// 7) Preorder Inorder Postorder Traversals in One Traversal
// Main Logic: Use one stack of {node, state} to perform all three traversals together.
// State 1 = Preorder: Root -> Left -> Right, so process node and then move left.
// State 2 = Inorder: Left -> Root -> Right, so process node and then move right.
// State 3 = Postorder: Left -> Right -> Root, so process node after both subtrees are done.
// void preInPostTraversal(Node* root){
//     if(root == nullptr) return ;
//     stack<pair<Node* , int>> st;
//     vector<int> pre , in , post;
//     st.push({root , 1});
//     while( ! st.empty()){
//         auto it = st.top();
//         st.pop();
//         if(it.second == 1){
//             pre.push_back(it.first->data); // State 1: Process node for preorder
//             it.second++;
//             st.push(it); // Put node back with state 2
//             if(it.first -> left != nullptr){
//                 st.push({it.first->left,1}); // Process left subtree
//             }
//         }
//         else if( it.second == 2){
//             in.push_back(it.first->data); // State 2: Process node for inorder
//             it.second++;
//             st.push(it); // Put node back with state 3
//             if(it.first->right != nullptr){
//                 st.push({it.first->right,1}); // Process right subtree
//             }
//         }
//         else {
//             post.push_back(it.first->data); // State 3: Process node for postorder
//         }
//     }
//     vector<vector<int>> ans = {pre,in,post};
//     for(auto x : ans){
//         for(auto val : x){
//             cout << val << " ";
//         }
//         cout << endl;
//     }
//     return;
// }

int main() {
    // Create the root node
    Node* root = new Node(1);
    // Create left and right children
    root->left = new Node(2);
    root->right = new Node(3);
    // Create right child of node 2
    root->left->right = new Node(5);

    // preorder(root); // Start preorder traversal
     
    // levelOrder(root);
    
    // preorderStack(root);

    // inorderStack(root);

    // postorder2Stack(root);

    // preInPostTraversal(root);

    return 0;
}