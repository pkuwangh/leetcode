/* Given a binary tree, determine if it is height-balanced.
 *
 * For this problem, a height-balanced binary tree is defined as a binary tree
 * in which the depth of the two subtrees of every node never differ by more than 1.
 */

// Definition for a binary tree node.

#include <algorithm>
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
    bool isBalanced(TreeNode* root) {
        return (checkHeight(root) != -1);
    }

    int checkHeight(TreeNode* root) {
        if (root == NULL) return 0;
        int lh = checkHeight(root->left);
        if (lh == -1) return -1;
        int rh = checkHeight(root->right);
        if (rh == -1) return -1;
        if (abs(lh - rh) > 1) return -1;
        return max(lh, rh) + 1;
    }
};

int main() {
    Solution obj;

    cout << obj.isBalanced(NULL) << endl;

    TreeNode *root = new TreeNode(0);
    root->left = new TreeNode(1);
    cout << obj.isBalanced(root) << endl;

    root->left->right = new TreeNode(2);
    cout << obj.isBalanced(root) << endl;

    return 0;
}
