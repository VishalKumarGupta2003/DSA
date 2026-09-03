// class Solution {
// public:
//     TreeNode* deleteNode(TreeNode* root, int key) {
//         if(!root) return NULL;
//         return search(root,key);
//     }
//     TreeNode* search(TreeNode* root, int key){
//         TreeNode* node = root;
//         TreeNode* prev = NULL;
//         while(node){
//             if(node->val == key){
//                 return deleteNode(root,node,prev);
//             }
//             if(node->val > key){
//                 prev = node;
//                 node = node->left;
//             }
//             else{
//                 prev = node;
//                 node = node->right;
//             }
//         }
//         return root;
//     }
//     TreeNode * deleteNode(TreeNode* root, TreeNode* node,TreeNode* prev){
        
//         if(!node->left && !node->right ){
//             if(node == root) return NULL;
//             else{
//                 if(prev->val < node->val){
//                     prev->right = NULL;
//                     return root;
//                 }
//                 else{
//                     prev->left = NULL;
//                     return root;
//                 }
//             }
//         }
//         if(!node->left){
//             if(node == root){
//                 return root->right;
//             }
//             else{
//                 if(node->val > prev->val) prev->right = node->right;
//                 else prev->left=node->right;
//                 return root;
//             }
//         }
//         if(!node->right){
//             if(node == root){
//                 return root->left;
//             }
//             else{
//                 if(node->val > prev->val) prev->right = node->left;
//                 else prev->left=node->left;
//                 return root;
//             }
//         }
//         TreeNode* nextNode = node->right;
//         TreeNode* cur= nextNode;
//         while(cur->left){
//             cur= cur->left;
//         }
//         cur->left=node->left;
//         if(root == node) return nextNode;
//         if(prev->val > node->val) prev->left = nextNode;
//         else prev->right = nextNode;
//         return root;
//     }
// };


// METHOD 2:-
// class Solution {
// public:
//     TreeNode* deleteNode(TreeNode* root, int key) {
//         if(root == NULL) {
//             return NULL;
//         }

//         if(root->val == key) {
//             return helper(root);
//         }

//         TreeNode* dummy = root;

//         while(root != NULL) {
//             if(root->val > key) {
//                 if(root->left != NULL && root->left->val == key) {
//                     root->left = helper(root->left);
//                     break;
//                 }
//                 else {
//                     root = root->left;
//                 }
//             }
//             else {
//                 if(root->right != NULL && root->right->val == key) {
//                     root->right = helper(root->right);
//                     break;
//                 }
//                 else {
//                     root = root->right;
//                 }
//             }
//         }

//         return dummy;
//     }

//     TreeNode* helper(TreeNode* root) {
//         if(root->left == NULL) {
//             return root->right;
//         }
//         else if(root->right == NULL) {
//             return root->left;
//         }

//         TreeNode* rightChild = root->right;
//         TreeNode* lastRight = findLastRight(root->left);

//         lastRight->right = rightChild;

//         return root->left;
//     }

//     TreeNode* findLastRight(TreeNode* root) {
//         if(root->right == NULL) {
//             return root;
//         }

//         return findLastRight(root->right);
//     }
// };