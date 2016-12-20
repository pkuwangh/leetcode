/* Given a binary tree and a sum,
 * find all root-to-leaf paths where each path's sum equals the given sum.
 *
 * For example:
 * Given the below binary tree and sum = 22,
 *               5
 *              / \
 *             4   8
 *            /   / \
 *           11  13  4
 *          /  \    / \
 *         7    2  5   1
 * return
 * [
 *   [5,4,11,2],
 *   [5,8,4,5]
 * ]
 */

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> all_sols;
        if (root != NULL) {
            vector<int> sol;
            findPath(root, sum, sol, all_sols);
        }
        return all_sols;
    }

    void findPath(TreeNode* node, int sum, vector<int>& sol, vector<vector<int>>& all_sols) {
        // push in current node
        sol.push_back(node->val);

        if (node->left || node->right) {
            // not a leaf
            // search left tree
            if (node->left) { findPath(node->left, sum - node->val, sol, all_sols); }
            // search right tree
            if (node->right) { findPath(node->right, sum - node->val, sol, all_sols); }
        } else {
            // a leaf node
            if (sum == node->val) {
                all_sols.push_back(sol);
            }
        }
        sol.pop_back();
    }
};

int main() {
    Solution obj;
    auto paths = obj.pathSum(NULL, 0);
    cout << paths.size() << endl;
    return 0;
}
