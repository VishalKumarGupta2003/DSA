// int kthSmallest(TreeNode* root, int k) {
//         TreeNode* cur=root;
//         int cnt=0;
//         int ans;
//         while(cur){
//             if(!cur->left) {
//                 cnt++;
//                 if(cnt == k) {
//                     ans=cur->val;
//                 }
//                 cur=cur->right;
//             }
//             else{
//                 TreeNode* prev = cur->left;
//                 while(prev->right  && prev->right != cur){
//                     prev=prev->right;
//                 }
//                 if(!prev->right){
//                     prev->right= cur;
//                     cur=cur->left;
//                 }
//                 else{
//                     prev->right=NULL;
//                     cnt++;
//                     if(cnt == k) {
//                         ans = cur->val;
//                     }
//                     cur=cur->right;
//                 }
//             }
//         }
//         return ans;
//     }
// };