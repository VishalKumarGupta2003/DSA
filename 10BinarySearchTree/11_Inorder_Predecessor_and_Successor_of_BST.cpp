#include <iostream>
#include <vector>
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
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        if(!root) return {};
        Node* pre = NULL;
        Node* suc = NULL;
        while(root){
            if(root->data > key){
                suc = root;
                root=root->left;
            }
            else if (root->data < key){
                pre = root;
                root= root->right;
            }
            else{
                if(root->left){
                    Node* temp = root->left;
                    while(temp->right){
                        temp = temp->right;
                    }
                    pre = temp;
                }
                if(root->right){
                    Node* temp  = root->right;
                    while(temp->left){
                        temp= temp->left;
                    }
                    suc=temp;
                }
                break;
            }
        }
        return {pre,suc};
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
    // For key = 20:
    // Predecessor = 15
    // Successor   = 25

    Node* root = new Node(20);

    root->left = new Node(10);
    root->right = new Node(30);

    root->left->left = new Node(5);
    root->left->right = new Node(15);

    root->right->left = new Node(25);
    root->right->right = new Node(35);

    int key = 20;

    Solution obj;

    vector<Node*> ans = obj.findPreSuc(root, key);

    cout << "Key: " << key << endl;

    if(ans[0])
        cout << "Predecessor: " << ans[0]->data << endl;
    else
        cout << "Predecessor: NULL" << endl;

    if(ans[1])
        cout << "Successor: " << ans[1]->data << endl;
    else
        cout << "Successor: NULL" << endl;

    return 0;
}

// ================= REVISION NOTES =================
//
// CENTRAL LOGIC:
// - Find predecessor = largest value smaller than key.
// - Find successor = smallest value greater than key.
// - While searching:
//      root > key → root is a successor candidate → go LEFT.
//      root < key → root is a predecessor candidate → go RIGHT.
// - If key is found:
//      predecessor = rightmost node of left subtree.
//      successor   = leftmost node of right subtree.
// - If key is NOT found, the candidates collected during traversal
//   are already the predecessor and successor.
//
// NORMAL FLOWCHART:
//
//                       START
//                         ↓
//                    root == NULL?
//                     /         \
//                   YES          NO
//                    ↓            ↓
//                  return     pre = NULL
//                    {}       suc = NULL
//                                  ↓
//                         Traverse BST
//                                  ↓
//                         root > key?
//                         /         \
//                       YES          NO
//                        ↓            ↓
//                  suc = root    root < key?
//                        ↓        /       \
//                    Go LEFT    YES        NO
//                                ↓          ↓
//                           pre = root   Key found
//                                ↓          ↓
//                            Go RIGHT   Find max in LEFT
//                                           ↓
//                                      Find min in RIGHT
//                                           ↓
//                                      Return {pre,suc}
//                                           ↓
//                                          END
//
// DATA STRUCTURES:
// - vector<Node*>:
//   Stores two pointers: {predecessor, successor}.
// - Node* pre:
//   Points to the predecessor node.
// - Node* suc:
//   Points to the successor node.
// - Node* temp:
//   Used to find the extreme node inside the left/right subtree.
//
// COMPLEXITY:
// - Time: O(h), where h = height of BST.
// - Space: O(1) auxiliary space.
//
// ==================================================