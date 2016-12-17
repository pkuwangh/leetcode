/* Given a binary tree, return the level order traversal of its nodes' values.
 * (ie, from left to right, level by level).
 *
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * return its level order traversal as:
 * [
 *  [3],
 *  [9,20],
 *  [15,7]
 * ]
 */

#include <vector>
#include <queue>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if (root == NULL) {
            return ret;
        }
        vector<int> nodes_same_level;
        queue<TreeNode*> node_queue;
        node_queue.push(root);
        int num_next = 1;
        int num_cur = 0;
        while (num_next > 0) {
            num_cur = num_next;
            num_next = 0;
            while (num_cur > 0) {
                TreeNode* node = node_queue.front();
                node_queue.pop();
                -- num_cur;
                nodes_same_level.push_back(node->val);
                if (node->left) {
                    ++ num_next;
                    node_queue.push(node->left);
                }
                if (node->right) {
                    ++ num_next;
                    node_queue.push(node->right);
                }
            }
            ret.push_back(nodes_same_level);
            nodes_same_level.clear();
        }
        return ret;
    }
};

int main() {
    Solution obj;
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    auto ans = obj.levelOrder(root);
    for (auto & vec : ans) {
        for (auto & val : vec) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}
