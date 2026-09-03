#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

class Solution {
public:
    int kthLargest(Node *root, int k) {
        Node* cur = root;
        int cnt = 0;
        int ans = -1;

        while(cur) {

            // No right subtree
            if(!cur->right) {
                cnt++;

                if(cnt == k)
                    ans = cur->data;

                cur = cur->left;
            }

            // Right subtree exists
            else {
                // Find inorder predecessor in reverse inorder.
                // Here, it is the leftmost node of right subtree.
                Node* prev = cur->right;

                while(prev->left && prev->left != cur) {
                    prev = prev->left;
                }

                // First time visiting cur
                if(!prev->left) {
                    // Create temporary thread
                    prev->left = cur;

                    // Move to right subtree
                    cur = cur->right;
                }

                // Second time visiting cur
                else {
                    // Remove temporary thread
                    prev->left = NULL;

                    cnt++;

                    if(cnt == k)
                        ans = cur->data;

                    // Move to left subtree
                    cur = cur->left;
                }
            }
        }

        return ans;
    }
};

int main() {

    /*
            5
           / \
          3   7
         / \ / \
        2  4 6  8
    */

    Node* root = new Node(5);

    root->left = new Node(3);
    root->right = new Node(7);

    root->left->left = new Node(2);
    root->left->right = new Node(4);

    root->right->left = new Node(6);
    root->right->right = new Node(8);

    Solution obj;

    int k = 3;

    cout << "The " << k << "rd largest element is: "
         << obj.kthLargest(root, k) << endl;

    return 0;
}

/*
===========================================================
MAIN LOGIC
===========================================================

We need the kth LARGEST element of a BST.

Normal inorder:

    LEFT -> ROOT -> RIGHT

gives:

    Smallest -> Largest

For kth LARGEST, we use reverse inorder:

    RIGHT -> ROOT -> LEFT

which gives:

    Largest -> Smallest


For the example:

            5
           / \
          3   7
         / \ / \
        2  4 6  8

Reverse inorder:

    8 -> 7 -> 6 -> 5 -> 4 -> 3 -> 2

Therefore:

    1st largest = 8
    2nd largest = 7
    3rd largest = 6
    4th largest = 5
    ...


===========================================================
MORRIS TRAVERSAL
===========================================================

We don't use recursion or a stack.

Therefore:

    Space = O(1)


For reverse inorder:

    RIGHT -> ROOT -> LEFT

When cur has a right subtree:

    Find the LEFTMOST node
    of cur's right subtree.

That node is called 'prev'.

Example:

        5
         \
          7
         /
        6

For cur = 5:

    prev = 7

    prev->left = 6

So move:

    prev = prev->left

Now:

    prev = 6

6 is the node that comes immediately before 5
in reverse inorder.


===========================================================
FIRST TIME
===========================================================

if(!prev->left)

There is no thread yet.

Create:

    prev->left = cur;

Then:

    cur = cur->right;

We move into the right subtree.


===========================================================
SECOND TIME
===========================================================

Eventually we return to cur through the temporary thread.

Now:

    prev->left == cur

So:

    prev->left = NULL;

Remove the temporary thread.

Now process cur:

    cnt++;

If:

    cnt == k

then:

    ans = cur->data;


===========================================================
CASE WHEN cur HAS NO RIGHT CHILD
===========================================================

if(!cur->right)

There is no right subtree to process.

Therefore we can directly process cur:

    cnt++;

Then move left:

    cur = cur->left;


===========================================================
WHY cnt?
===========================================================

cnt tells us how many nodes have been visited
in reverse inorder.

Because reverse inorder gives:

    Largest -> Smallest

the kth visited node is the kth largest.

So:

    if(cnt == k)
        ans = cur->data;


===========================================================
COMPLEXITY
===========================================================

Time Complexity:

    O(N)

Space Complexity:

    O(1)

because Morris traversal does not use recursion
or an explicit stack.

===========================================================
*/