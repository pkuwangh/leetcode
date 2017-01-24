/* Given a binary tree containing digits from 0-9 only,
 * each root-to-leaf path could represent a number.
 * An example is the root-to-leaf path 1->2->3 which represents the number 123.
 * Find the total sum of all root-to-leaf numbers.
 * For example,
 *     1
 *    / \
 *   2   3
 * The root-to-leaf path 1->2 represents the number 12.
 * The root-to-leaf path 1->3 represents the number 13.
 * Return the sum = 12 + 13 = 25.
 */
#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
    int sumNumbers(TreeNode* root) {
        if (root == NULL) return 0;
        int total_sum = 0;
        // level ordering BFS
        int cur = 0, next = 1;
        queue<pair<TreeNode*, int>> node_sums;
        node_sums.push(make_pair(root, 0));
        while (next > 0) {
            cur = next;
            next = 0;
            while (cur > 0) {
                auto node_sum = node_sums.front();
                -- cur;
                node_sums.pop();
                TreeNode* node = node_sum.first;
                int sum = node_sum.second;
                int newsum = 10*sum + node->val;
                if (node->left || node->right) {
                    if (node->left) {
                        ++ next;
                        node_sums.push(make_pair(node->left, newsum));
                    }
                    if (node->right) {
                        ++ next;
                        node_sums.push(make_pair(node->right, newsum));
                    }
                } else {
                    total_sum += newsum;
                }
            }
        }
        return total_sum;
    }
};

int main() {
    Solution obj;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    cout << obj.sumNumbers(root) << endl;
    root->right->left = new TreeNode(4);
    cout << obj.sumNumbers(root) << endl;
    return 0;
}
