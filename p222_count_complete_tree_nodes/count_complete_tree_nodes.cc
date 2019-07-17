/**
 * Given a complete binary tree, count the number of nodes.
 * Note:
 * Definition of a complete binary tree from Wikipedia:
 * In a complete binary tree every level, except possibly the last,
 * is completely filled, and all nodes in the last level are as far left as possible.
 * It can have between 1 and 2h nodes inclusive at the last level h.
 * Example:
 * Input: 
 *     1
 *    / \
 *   2   3
 *  / \  /
 * 4  5 6
 * Output: 6
*/

#include <queue>
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
    int countNodes(TreeNode* root) {
        // bfs
        /*
        queue<TreeNode*> bfs_q;
        if (root == nullptr) return 0;
        int count = 0;
        bfs_q.push(root);
        while (!bfs_q.empty()) {
            ++ count;
            TreeNode* node = bfs_q.front();
            bfs_q.pop();
            if (node->left) {
                bfs_q.push(node->left);
            }
            if (node->right) {
                bfs_q.push(node->right);
            }
        }
        return count;
        */

        // recursively adds sub- complete binary tree
        if (root == nullptr) return 0;
        int left_depth = 0;
        int right_depth = 0;
        TreeNode* node = root;
        while (node) {
            node = node->left;
            ++ left_depth;
        }
        node = root;
        while (node) {
            node = node->right;
            ++ right_depth;
        }
        // if it is a complete tree
        if (left_depth == right_depth) {
            return (1 << left_depth) - 1;
        } else {
            return 1 + countNodes(root->left) + countNodes(root->right);
        }
    }
};

int main() {
    Solution obj;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    cout << obj.countNodes(root) << endl;
    return 0;
}
