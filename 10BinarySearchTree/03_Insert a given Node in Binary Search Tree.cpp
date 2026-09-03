// METHOD 1:- INSERTING AS LEAF NODE
// TreeNode* insertIntoBST(TreeNode* root, int val) {
//         if(!root) {
//             return new TreeNode(val);
//         }
//         TreeNode* node = root;
//         while(root){
//             if(root->val < val){
//                 if(root->right){
//                     root = root->right;
//                 }
//                 else {
//                     root->right = new TreeNode(val);;
//                     break;
//                 }
//             }
//             else{
//                 if(root->left) root=root->left;
//                 else {
//                     root->left = new TreeNode(val);;
//                     break;
//                 }
                
//             }
//         }
//         return node;
//     }