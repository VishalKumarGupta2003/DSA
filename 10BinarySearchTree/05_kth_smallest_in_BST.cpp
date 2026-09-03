// int kthSmallest(TreeNode* root, int k) {

//     TreeNode* cur = root;
//     int cnt = 0;
//     int ans;

//     while(cur) {

//         // No left subtree
//         if(!cur->left) {

//             // Current node is the next node in inorder
//             cnt++;

//             if(cnt == k) {
//                 ans = cur->val;
//             }

//             cur = cur->right;
//         }

//         else {

//             // Find inorder predecessor:
//             // rightmost node in cur's left subtree
//             TreeNode* prev = cur->left;

//             while(prev->right && prev->right != cur) {
//                 prev = prev->right;
//             }

//             // First time reaching cur
//             if(!prev->right) {

//                 // Create temporary thread
//                 prev->right = cur;

//                 // Go to left subtree
//                 cur = cur->left;
//             }

//             // Second time reaching cur
//             else {

//                 // Remove temporary thread
//                 prev->right = NULL;

//                 // Now process cur
//                 cnt++;

//                 if(cnt == k) {
//                     ans = cur->val;
//                 }

//                 // Move to right subtree
//                 cur = cur->right;
//             }
//         }
//     }

//     return ans;
// }