#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr) return ans;
        bool leftToRight = true;
        queue<TreeNode*> nodesQueue;
        nodesQueue.push(root);
        while(!nodesQueue.empty()){
            int size = nodesQueue.size();
            vector<int> row(size);
            for(int i=0;i<size;i++){
                TreeNode* nodes = nodesQueue.front();
                nodesQueue.pop();
                int index = (leftToRight) ? i : (size-i-1);
                row[index] = nodes->val;
                if(nodes->left){
                    nodesQueue.push(nodes->left);
                }
                if(nodes->right){
                    nodesQueue.push(nodes->right);
                }
            }
            leftToRight = !leftToRight;
            ans.push_back(row);
        }
        return ans;
    }
};
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    Solution obj;
    vector<vector<int>> result = obj.zigzagLevelOrder(root);
    for(auto row : result){
        for(int val : row){
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}
// MAIN LOGIC:
// We use a queue to perform normal level-order traversal.
// For every level, we first store its number of nodes using size.
// A separate row vector is created to store all nodes of the current level.
// When leftToRight is true, nodes are stored at index i, giving left-to-right order.
// When leftToRight is false, nodes are stored at index size-i-1, giving right-to-left order.
// The left and right children of every node are pushed into the queue for the next level.
// After processing each level, leftToRight is toggled to change the traversal direction.
// Finally, every completed row is added to ans and ans is returned.
// Time Complexity: O(N), where N is the number of nodes.
// Space Complexity: O(N) for the queue and answer.