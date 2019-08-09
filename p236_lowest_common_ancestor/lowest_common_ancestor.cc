/**
 * Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
 *  According to the definition of LCA on Wikipedia:
 * “The lowest common ancestor is defined between two nodes p and q as the lowest node in T
 * that has both p and q as descendants (where we allow a node to be a descendant of itself).”
 *  Given the following binary tree:  root = [3,5,1,6,2,0,8,null,null,7,4]
 *  Example 1:
 * Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
 * Output: 3
 * Explanation: The LCA of nodes 5 and 1 is 3.
 * Example 2:
 * Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
 * Output: 5
 * Explanation: The LCA of nodes 5 and 4 is 5,
 * since a node can be a descendant of itself according to the LCA definition.
 * Note:
 * All of the nodes' values will be unique.
 * p and q are different and both values will exist in the binary tree.
 */

#include <cassert>
#include <cstdint>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <list>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <functional>
#include <algorithm>
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return get<0>(dfs(root, p, q));
    }

    tuple<TreeNode*, bool, bool> dfs(TreeNode* root, const TreeNode* p, const TreeNode* q)
    {
        if (root == nullptr) return make_tuple(nullptr, false, false);
        auto lret = dfs(root->left, p, q);
        auto rret = dfs(root->right, p, q);
        if (get<0>(lret) != nullptr) {
            return lret;
        } else if (get<0>(rret) != nullptr) {
            return rret;
        } else {
            bool p_val = false;
            bool q_val = false;
            if (get<1>(lret) || get<1>(rret) || root == p) p_val = true;
            if (get<2>(lret) || get<2>(rret) || root == q) q_val = true;
            if (p_val && q_val) {
                return make_tuple(root, true, true);
            } else {
                return make_tuple(nullptr, p_val, q_val);
            }
        }
    }
};

int main() {
    TreeNode* root = new TreeNode(0);
    root->left = new TreeNode(1);
    root->right = new TreeNode(2);
    Solution obj;
    auto run = [&](TreeNode* root, TreeNode* p, TreeNode* q) ->void {
        cout << obj.lowestCommonAncestor(root, p, q)->val << endl;
    };
    run(root, root->left, root->right);
    return 0;
}
