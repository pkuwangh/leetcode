/**
 * The thief has found himself a new place for his thievery again.
 * There is only one entrance to this area, called the "root."
 * Besides the root, each house has one and only one parent house.
 * After a tour, the smart thief realized that
 * "all houses in this place forms a binary tree".
 * It will automatically contact the police if two directly-linked houses
 * were broken into on the same night.
 * 
 * Determine the maximum amount of money the thief can rob tonight
 * without alerting the police.
 * Example 1:
 * Input: [3,2,3,null,3,null,1]
 *      3
 *     / \
 *    2   3
 *     \   \
 *      3   1
 * Output: 7
 * Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
 *
 * Example 2:
 * Input: [3,4,5,1,3,null,1]
 *      3
 *     / \
 *    4   5
 *   / \   \
 *  1   3   1
 * Output: 9
 * Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.
 */

#include <cstdint>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  private:
    map<TreeNode*, int> dict_alarm;
    map<TreeNode*, int> dict_free;

  public:
    int rob(TreeNode* root) {
        return dfs(root, false);
    }

    int get_val(TreeNode* node, bool alarm) {
        if (alarm) {
            if (dict_alarm.count(node) > 0) {
                return dict_alarm[node];
            } else {
                int val = dfs(node, true);
                dict_alarm[node] = val;
                return val;
            }
        } else {
            if (dict_free.count(node) > 0) {
                return dict_free[node];
            } else {
                int val = dfs(node, false);
                dict_free[node] = val;
                return val;
            }
        }
    }

    int dfs(TreeNode* root, bool alarm) {
        if (root == nullptr) return 0;
        if (alarm) {
            // cannot rob this node
            return get_val(root->left, false) + get_val(root->right, false);
        } else {
            // choose max of two options
            int rob_option = root->val + get_val(root->left, true) + get_val(root->right, true);
            int skip_option = get_val(root->left, false) + get_val(root->right, false);
            return max(rob_option, skip_option);
        }
    }
};

int main() {
    TreeNode* root;
    root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right = new TreeNode(5);
    root->right->right = new TreeNode(1);
    Solution obj;
    cout << obj.rob(root) << endl;
    return 0;
}
