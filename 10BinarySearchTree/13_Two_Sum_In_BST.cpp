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

class BTSIterator{
    stack<TreeNode*> st;
    bool reverse = true;
public:
    BTSIterator(TreeNode *root, bool isReverse){
        reverse = isReverse;
        pushAll(root, reverse);
    }
    bool hasNext(){
        return !st.empty();
    }
    int next(){
        TreeNode * root = st.top();
        st.pop();
        if(!reverse) pushAll(root->right , reverse);
        else pushAll(root->left,reverse);
        return root->val;
    }
private:
    void pushAll(TreeNode* root , bool reverse){
        for( ; root ; ){
            st.push(root);
            if(reverse) root=root->right;
            else root = root->left;
        }
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        BTSIterator l(root ,false);
        BTSIterator r(root,true);
        int i = l.next();
        int j= r.next();
        while(i < j){
            if(i + j == k) return true;
            else if(i+j < k) i = l.next();
            else j = r.next();
        }
        return false;
    }
};

int main() {

    // Creating BST:
    //
    //             5
    //           /   \
    //          3     6
    //         / \     \
    //        2   4     7
    //
    // Inorder: 2 3 4 5 6 7
    //
    // For k = 9:
    // 2 + 7 = 9 → true

    TreeNode* root = new TreeNode(5);

    root->left = new TreeNode(3);
    root->right = new TreeNode(6);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);

    root->right->right = new TreeNode(7);

    int k = 9;

    Solution obj;

    bool ans = obj.findTarget(root, k);

    cout << boolalpha;
    cout << "Target " << k << " exists: " << ans << endl;

    return 0;
}

// ================= REVISION NOTES =================
//
// CENTRAL LOGIC:
// - Use TWO BST iterators simultaneously.
// - Normal iterator gives values in ASCENDING order:
//      LEFT → ROOT → RIGHT
// - Reverse iterator gives values in DESCENDING order:
//      RIGHT → ROOT → LEFT
// - `i` starts from the smallest value.
// - `j` starts from the largest value.
// - If i + j == k → pair found.
// - If i + j < k → need a larger value → move i forward.
// - If i + j > k → need a smaller value → move j backward.
// - This is essentially the two-pointer technique applied to a BST.
//
// NORMAL FLOWCHART:
//
//                       START
//                         ↓
//                    root == NULL?
//                    /          \
//                  YES           NO
//                   ↓             ↓
//                false      Create 2 iterators
//                                ↓
//                    l = ascending iterator
//                    r = descending iterator
//                                ↓
//                     i = l.next(), j = r.next()
//                                ↓
//                            i < j?
//                          /        \
//                        NO          YES
//                        ↓             ↓
//                      false       i + j == k?
//                                  /       \
//                                YES        NO
//                                 ↓          ↓
//                               true     i + j < k?
//                                           /    \
//                                         YES     NO
//                                          ↓       ↓
//                                     i = l.next() j = r.next()
//                                          \       /
//                                           \     /
//                                            REPEAT
//
// DATA STRUCTURES:
//
// - stack<TreeNode*> st:
//   Stores the path of nodes that are waiting to be processed.
//   It allows the iterator to simulate inorder/reverse-inorder traversal.
//
// - BTSIterator l:
//   Uses normal inorder traversal.
//   Gives: smallest → largest.
//
// - BTSIterator r:
//   Uses reverse inorder traversal.
//   Gives: largest → smallest.
//
// - TreeNode:
//   Stores the node value and pointers to left/right children.
//
// IMPORTANT ITERATOR LOGIC:
//
// reverse = false:
//     LEFT → ROOT → RIGHT
//     Gives ascending order.
//
// reverse = true:
//     RIGHT → ROOT → LEFT
//     Gives descending order.
//
// pushAll():
// - reverse == false → push LEFT chain.
// - reverse == true  → push RIGHT chain.
//
// next():
// - Take the top node from stack.
// - Move into its opposite subtree.
// - Push that subtree's appropriate chain.
//
// COMPLEXITY:
// - Time: O(n) in the worst case.
// - Auxiliary Space: O(h), where h = height of BST.
// - We don't convert the BST into an array, so we save O(n) extra
//   space compared with storing the complete inorder traversal.
//
// ==================================================