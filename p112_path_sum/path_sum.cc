/* Given a binary tree and a sum, determine if the tree has a root-to-leaf path
 * such that adding up all the values along the path equals the given sum.
 *
 * For example:
 * Given the below binary tree and sum = 22,
 *               5
 *              / \
 *             4   8
 *            /   / \
 *           11  13  4
 *          /  \      \
 *         7    2      1
 * return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
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
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) {
            return false;
        } else {
            return hasSubPathSum(root, sum);
        }
    }

    bool hasSubPathSum(TreeNode* node, int sum) {
        if (node->left || node->right) {
            // not a leaf
            bool found_in_left = false;
            bool found_in_right = false;
            if (node->left) {
                found_in_left = hasSubPathSum(node->left, sum - node->val);
            }
            if (node->right) {
                found_in_right = hasSubPathSum(node->right, sum - node->val);
            }
            return found_in_left || found_in_right;
        } else {
            return (sum == node->val);
        }
    }
};

int main() {
    Solution obj;
    cout << obj.hasPathSum(NULL, 0) << endl;
}
