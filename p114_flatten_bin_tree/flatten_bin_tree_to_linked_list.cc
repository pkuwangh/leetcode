/* Given a binary tree, flatten it to a linked list in-place.
 * For example,
 * Given
 *          1
 *         / \
 *        2   5
 *       / \   \
 *      3   4   6
 * The flattened tree should look like:
 *   1
 *    \
 *     2
 *      \
 *       3
 *        \
 *         4
 *          \
 *           5
 *            \
 *             6
 */

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
    void flatten(TreeNode* root) {
        if (root == NULL) return;
        flattenSubTree(root);
    }

    // flatten subtree and return the rightmost node.
    TreeNode* flattenSubTree(TreeNode* root) {
        TreeNode* rightmost = root;
        // flatten left subtree and connect
        if (root->left) {
            TreeNode* rightmost_leftsubtree = flattenSubTree(root->left);
            rightmost_leftsubtree->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
        // find right most and flatten right subtree
        if (root->right) {
            rightmost = flattenSubTree(root->right);
        }
        return rightmost;
    }
};

int main() {
    Solution obj;
#if 0
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
#endif
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    obj.flatten(root);
    while (root != NULL) {
        cout << root->val << " ";
        root = root->right;
    }
    cout << endl;
    return 0;
}
