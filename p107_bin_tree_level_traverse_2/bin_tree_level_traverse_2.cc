/* Given a binary tree, return the bottom-up level order traversal of its nodes' values.
 * (ie, from left to right, level by level from leaf to root).
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * return its bottom-up level order traversal as:
 * [
 *   [15,7],
 *   [9,20],
 *   [3]
 * ]
 */

#include <iostream>
#include <vector>
#include <queue>
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ret;
        vector<int> row;
        queue<TreeNode*> nodes;
        int next = 0, cur = 0;
        if (root) {
            nodes.push(root);
            next = 1;
        }
        // BFS
        while (next > 0) {
            cur = next;
            next = 0;
            while (cur > 0) {
                TreeNode* node = nodes.front();
                nodes.pop();
                -- cur;
                row.push_back(node->val);
                if (node->left) {
                    ++ next;
                    nodes.push(node->left);
                }
                if (node->right) {
                    ++ next;
                    nodes.push(node->right);
                }
            }
            ret.push_back(row);
            row.clear();
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

int main() {
    Solution obj;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    auto ans = obj.levelOrderBottom(root);
    for (auto &row : ans) {
        for (auto &n : row) {
            cout << n << " ";
        }
        cout << endl;
    }
    return 0;
}
