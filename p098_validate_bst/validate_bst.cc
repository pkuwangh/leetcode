/* Given a binary tree, determine if it is a valid binary search tree (BST).
 * Assume a BST is defined as follows:
 * The left subtree of a node contains only nodes with keys less than the node's key.
 * The right subtree of a node contains only nodes with keys greater than the node's key.
 * Both the left and right subtrees must also be binary search trees.
 * Example 1:
 *     2
 *    / \
 *   1   3
 * Binary tree [2,1,3], return true.
 * Example 2:
 *     1
 *    / \
 *   2   3
 * Binary tree [1,2,3], return false.
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
#if 0
    bool isValidBST(TreeNode* root) {
        if (root == NULL) return true;
        return isValidSubTree(root, 0, false, 0, false);
    }

    bool isValidSubTree(TreeNode *root, int maxVal, bool maxSet, int minVal, bool minSet) {
        if (root == NULL) return true;
        if (root->left) {
            if (root->left->val >= root->val) return false;
            if (minSet && root->left->val <= minVal) return false;
            if (!isValidSubTree(root->left, root->val, true, minVal, minSet)) return false;
        }
        if (root->right) {
            if (root->right->val <= root->val) return false;
            if (maxSet && root->right->val >= maxVal) return false;
            if (!isValidSubTree(root->right, maxVal, maxSet, root->val, true)) return false;
        }
        return true;
    }
#endif

    bool isValidBST(TreeNode* root) {
        return validateBST(root, 0, false, 0, false);
    }

    bool validateBST(TreeNode *root, int maxVal, bool maxSet, int minVal, bool minSet) {
        if (root == NULL) return true;
        if (maxSet && root->val >= maxVal) return false;
        if (minSet && root->val <= minVal) return false;
        return validateBST(root->left, root->val, true, minVal, minSet) &&
               validateBST(root->right, maxVal, maxSet, root->val, true);
    }
};

int main() {
    Solution obj;
    cout << obj.isValidBST(NULL) << endl;
    return 0;
}
