/* Given a binary tree, find its maximum depth.
 * The maximum depth is the number of nodes along the longest path
 * from the root node down to the farthest leaf node.
 */

#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        int left_depth = 1;
        if (root->left != NULL) {
            left_depth += maxDepth(root->left);
        }
        int right_depth = 1;
        if (root->right != NULL) {
            right_depth += maxDepth(root->right);
        }
        return max(left_depth, right_depth);
    }
};

int main() {
    Solution obj;
    cout << obj.maxDepth(NULL) << endl;
    return 0;
}
