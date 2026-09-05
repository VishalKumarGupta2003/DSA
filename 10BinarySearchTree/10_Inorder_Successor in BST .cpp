// METHOD 1: Using Inorder Traversal STORE THE NODES IN AN ARRAY AND RETURN THE SUCCESSOR
// METHOD 2:- INSTEAD OF STORING THE NODES IN AN ARRAY, WE CAN RETURN THE FIRST NODE > THAN NODE
// METHOD 3:- 
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
  public:
    int inOrderSuccessor(Node *root, Node *k) {
        // code here
        if(!root) return -1;
        int successor = -1;
        while(root){
            if(root->data > k->data){
                successor = root->data;
                root=root->left;
            }
            else root=root->right;
        }
        return successor;
    }
};

int main() {

    // Creating BST:
    //
    //          20
    //        /    \
    //      10      30
    //     /  \    /  \
    //    5   15  25   35
    //
    // Inorder: 5 10 15 20 25 30 35

    Node* root = new Node(20);

    root->left = new Node(10);
    root->right = new Node(30);

    root->left->left = new Node(5);
    root->left->right = new Node(15);

    root->right->left = new Node(25);
    root->right->right = new Node(35);

    Node* k = root->left;   // k = 10

    Solution obj;

    int ans = obj.inOrderSuccessor(root, k);

    cout << "Inorder Successor of " << k->data << ": " << ans << endl;

    return 0;
}

// ================= REVISION NOTES =================
//
// CENTRAL LOGIC:
// - Inorder successor = smallest value greater than k.
// - Traverse the BST from root.
// - If root->data > k->data:
//      → root can be a successor.
//      → Store it and move LEFT to find a smaller successor.
// - Otherwise:
//      → root cannot be the successor.
//      → Move RIGHT.
// - The last stored candidate is the inorder successor.
//
// NORMAL FLOWCHART:
//
//                  START
//                    ↓
//                root == NULL?
//                 /       \
//               YES        NO
//                ↓          ↓
//             return -1   successor = -1
//                           ↓
//                      Traverse BST
//                           ↓
//                   root->data > k?
//                     /          \
//                   YES           NO
//                    ↓             ↓
//             store root->data   Go RIGHT
//                    ↓
//                 Go LEFT
//                    ↓
//              Repeat until NULL
//                    ↓
//          Return stored successor
//                    ↓
//                   END
//
// DATA STRUCTURES:
// - BST:
//   Stores values such that smaller values are on the left
//   and larger values are on the right.
// - Node*:
//   Stores the address of the current BST node.
// - successor:
//   Stores the best candidate found so far.
//
// COMPLEXITY:
// - Time: O(h), where h = height of BST.
// - Space: O(1) because traversal is iterative.
//
// ==================================================