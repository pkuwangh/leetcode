/* Given a binary tree, return the zigzag level order traversal of its nodes' values.
 * (ie, from left to right, then right to left for the next level and alternate between).
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * return its zigzag level order traversal as:
 * [
 *   [3],
 *   [20,9],
 *   [15,7]
 * ]
 */

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if (root == NULL) return ret;

        vector<int> row;
        deque<TreeNode*> node_deque;
        node_deque.push_back(root);
        int num_next = 1;
        int num_cur = 0;
        bool left_to_right = true;

        while (num_next > 0) {
            num_cur = num_next;
            num_next = 0;

            while (num_cur > 0) {
                TreeNode* node = NULL;
                if (left_to_right) {
                    node = node_deque.front();
                    node_deque.pop_front();
                    if (node->left) {
                        ++ num_next;
                        node_deque.push_back(node->left);
                    }
                    if (node->right) {
                        ++ num_next;
                        node_deque.push_back(node->right);
                    }
                } else {
                    node = node_deque.back();
                    node_deque.pop_back();
                    if (node->right) {
                        ++ num_next;
                        node_deque.push_front(node->right);
                    }
                    if (node->left) {
                        ++ num_next;
                        node_deque.push_front(node->left);
                    }
                }
                row.push_back(node->val);
                -- num_cur;
            }
            ret.push_back(row);
            row.clear();
            left_to_right = !left_to_right;
        }
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
    auto ans = obj.zigzagLevelOrder(root);
    for (auto &row : ans) {
        for (auto &n : row) {
            cout << n << " ";
        }
        cout << endl;
    }
    return 0;
}
