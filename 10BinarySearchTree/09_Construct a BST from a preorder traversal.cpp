#include <iostream>
#include <vector>
#include <climits>
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

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int ub=INT_MAX;
        int i=0;
        return bstFromPreorder(preorder,i,ub);
    }
    TreeNode* bstFromPreorder(vector<int>& preorder,int &i,int ub){
        if(i >= preorder.size() || preorder[i] > ub) return NULL;
        TreeNode* root = new TreeNode(preorder[i++]);
        root->left =  bstFromPreorder(preorder,i,root->val);
        root->right = bstFromPreorder(preorder,i,ub);
        return root;
    }
};

int main() {

    vector<int> preorder = {8, 5, 1, 7, 10, 12};

    Solution obj;

    TreeNode* root = obj.bstFromPreorder(preorder);

    // Inorder traversal to verify the BST
    // Expected: 1 5 7 8 10 12

    cout << "Inorder: ";

    // Simple iterative inorder traversal
    vector<TreeNode*> st;
    TreeNode* cur = root;

    while(cur || !st.empty()) {

        while(cur) {
            st.push_back(cur);
            cur = cur->left;
        }

        cur = st.back();
        st.pop_back();

        cout << cur->val << " ";

        cur = cur->right;
    }

    cout << endl;

    return 0;
}

// ================= REVISION NOTES =================
//
// CENTRAL LOGIC:
// - Preorder = ROOT → LEFT → RIGHT.
// - `i` points to the next unused element in preorder.
// - `ub` represents the maximum value allowed in the current subtree.
// - Create the current root from preorder[i] and increment i.
// - Recursively construct LEFT using root->val as the upper bound.
// - Recursively construct RIGHT using the previous upper bound.
// - If preorder[i] > ub, the value belongs to another subtree,
//   so return NULL without increasing i.
//
// NORMAL FLOWCHART:
//
//                    START
//                      ↓
//               i >= n OR
//             preorder[i] > ub?
//                 /       \
//               YES        NO
//                ↓          ↓
//             return NULL  Create root
//                            ↓
//                           i++
//                            ↓
//                    Build LEFT subtree
//                    ub = root->val
//                            ↓
//                   Build RIGHT subtree
//                       same ub
//                            ↓
//                       return root
//                            ↓
//                           END
//
// DATA STRUCTURES:
// - vector<int> preorder:
//   Stores the given preorder traversal.
// - TreeNode:
//   Stores value, left-child pointer and right-child pointer.
// - int i:
//   Shared index tracking the next preorder element.
// - int ub:
//   Upper bound controlling which values can belong to the
//   current subtree.
//
// COMPLEXITY:
// - Time: O(n)
// - Space: O(h), where h is the height of the constructed BST.
//
// ==================================================