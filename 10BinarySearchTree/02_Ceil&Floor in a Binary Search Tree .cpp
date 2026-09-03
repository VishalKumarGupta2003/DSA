// int findCeil(Node* root, int x) {
//         int ceil=-1;
//         while(root){
//             if(root->data == x) return x;
//             if(root->data > x) {
//                 ceil = root->data;
//                 root=root->left;
//             }
//             else root = root->right;
//         }
//         return ceil;
//     }

// int findMaxFloor(Node* root, int x) {
//         // code here
//         int floor=-1;
//         while(root){
//             if(root->data == x) return x;
//             if(root->data < x) {
//                 floor = root->data;
//                 root=root->right;
//             }
//             else root = root->left;
//         }
//         return floor;
//     }