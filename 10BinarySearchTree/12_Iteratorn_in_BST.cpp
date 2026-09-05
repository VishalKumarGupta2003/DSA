#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

class BSTIterator {
private: stack<TreeNode*> st;
public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode * node = st.top();
        st.pop();
        pushAll(node->right);
        return node->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
private: 
    void pushAll(TreeNode* root){
        for(; root!=NULL; st.push(root),root= root->left);
    }
    //     while (root != NULL) {
    //     st.push(root);
    //     root = root->left;
    // }

    
};

int main() {

    // Creating BST:
    //
    //          7
    //        /   \
    //       3     15
    //      / \    / \
    //     1   5  9   20
    //
    // Inorder: 1 3 5 7 9 15 20

    TreeNode* root = new TreeNode(7);

    root->left = new TreeNode(3);
    root->right = new TreeNode(15);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);

    BSTIterator obj(root);

    cout << "BST elements in ascending order: ";

    while(obj.hasNext()) {
        cout << obj.next() << " ";
    }

    cout << endl;

    return 0;
}

// ================= REVISION NOTES =================
//
// CENTRAL LOGIC:
// - Inorder traversal of a BST gives values in sorted order.
// - Instead of storing the complete inorder traversal, use a stack
//   to simulate it.
// - pushAll() pushes the complete LEFT chain into the stack.
// - Therefore, the stack TOP always contains the next smallest node.
// - next():
//      1. Pop the top node.
//      2. Push the left chain of its right subtree.
//      3. Return the popped node's value.
// - hasNext() checks whether any unprocessed node remains.
//
// NORMAL FLOWCHART:
//
//                    START
//                      ↓
//               pushAll(root)
//                      ↓
//             Push complete LEFT chain
//                      ↓
//                 hasNext()?
//                  /       \
//                NO         YES
//                 ↓           ↓
//                END        next()
//                             ↓
//                       Pop top node
//                             ↓
//                  Push LEFT chain of
//                    right subtree
//                             ↓
//                       Return value
//                             ↓
//                       Repeat
//
// DATA STRUCTURES:
// - stack<TreeNode*> st:
//   Stores node pointers that are waiting to be processed.
// - TreeNode:
//   Stores value + left-child pointer + right-child pointer.
// - Stack TOP:
//   Always represents the next smallest unprocessed BST node.
//
// FOR LOOP:
// - for(; root!=NULL; st.push(root),root= root->left);
// - Initialization → empty.
// - Condition → root != NULL.
// - Update → push current node, then move to left child.
// - Body → empty because of the final semicolon.
// - Equivalent to:
//
//   while(root != NULL) {
//       st.push(root);
//       root = root->left;
//   }
//
// COMPLEXITY:
// - Constructor: O(h)
// - next(): Amortized O(1)
// - hasNext(): O(1)
// - Space: O(h), where h = height of BST.
//
// ==================================================