/**
 * Given a non-empty binary tree, find the maximum path sum.
 * For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections.
 * The path must contain at least one node and does not need to go through the root.
 * Example 1:
 * Input: [1,2,3]
 *        1
 *       / \
 *      2   3
 * Output: 6
 * Example 2:
 * Input: [-10,9,20,null,null,15,7]
 *    -10
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * Output: 42
 */

#include <algorithm>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
  public:
    int maxPathSum(TreeNode* root) {
        if (root == nullptr) return 0;
        int max_sum = root->val;
        maxPath(root, max_sum);
        return max_sum;
    }

    int maxPath(TreeNode* root, int& max_sum) {
        if (root == nullptr) return 0;
        int left_path = max(0, maxPath(root->left, max_sum));
        int right_path = max(0, maxPath(root->right, max_sum));
        int sum = left_path + right_path + root->val;
        max_sum = max(sum, max_sum);
        return max(left_path, right_path) + root->val;
    }
};

int main() {
    Solution obj;
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    cout << obj.maxPathSum(root1) << endl;

    TreeNode* root2 = new TreeNode(-10);
    root2->left = new TreeNode(9);
    root2->right = new TreeNode(20);
    root2->right->left = new TreeNode(15);
    root2->right->right = new TreeNode(7);
    cout << obj.maxPathSum(root2) << endl;
}
