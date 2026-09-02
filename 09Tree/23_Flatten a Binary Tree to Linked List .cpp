// Reverse Postorder Tree Flattening
// void solve(TreeNode* root,TreeNode* &prev){
//         if(!root) return;
//         if(root->right) solve(root->right,prev);
//         if(root->left) solve(root->left,prev);
//         root->right = prev;
//         root->left=NULL;
//         prev =root;
//     }
//     void flatten(TreeNode* root) {
//         TreeNode* prev = NULL;
//         solve(root,prev);
//         return;
//     }


// Method 2:- Using Stack
// class Solution {
// public:
//     void flatten(TreeNode* root) {
//         if(!root) return ;
//         stack<TreeNode*> st;
//         st.push(root);
//         while(!st.empty()){
//             TreeNode * node = st.top();
//             st.pop();
//             if(node->right) st.push(node->right);
//             if(node->left) st.push(node->left);
//             if(!st.empty()){
//                 node->right = st.top();
//                 node->left = NULL;
//             }
//         }
//         return ;
//     }
// };

// Method 3:- Using Morris Traversal
// void flatten(TreeNode* root) {
//         if(!root) return ;
//         TreeNode* cur = root;
//         while(cur){
//             if(cur->left){
//                 TreeNode* prev = cur->left;
//                 while(prev->right){
//                     prev=prev->right;
//                 }                
//                 prev->right = cur->right;
//                 cur->right=cur->left;
//                 cur->left=NULL;
//             }
//             cur=cur->right;
//         }
//     }