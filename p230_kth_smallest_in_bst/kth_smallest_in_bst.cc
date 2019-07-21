/**
 * Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
 * Example 1:
 * Input: root = [3,1,4,null,2], k = 1
 *    3
 *   / \
 *  1   4
 *   \
 *    2
 * Output: 1
 * Example 2:
 * Input: root = [5,3,6,2,4,null,null,1], k = 3
 *        5
 *       / \
 *      3   6
 *     / \
 *    2   4
 *   /
 *  1
 * Output: 3
 * Follow up:
 * What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?
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
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        int kval = 0;
        dfs(root, k, cnt, kval);
        return kval;
    }

    bool dfs(const TreeNode* root, const int& k, int& cnt, int& kval) {
        if (root == nullptr) return false;
        // left
        if (root->left) {
            if (dfs(root->left, k, cnt, kval)) {
                return true;
            }
        }
        // node itself
        ++ cnt;
        if (cnt == k) {
            kval = root->val;
            return true;
        }
        // right
        if (root->right) {
            if (dfs(root->right, k, cnt, kval)) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution obj;
    auto run = [&](TreeNode* root, int k) ->void {
        cout << obj.kthSmallest(root, k) << endl;
    };
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(1);
    root1->left->right = new TreeNode(2);
    root1->right = new TreeNode(4);
    run(root1, 1);
    TreeNode* root2 = new TreeNode(5);
    root2->left = new TreeNode(3);
    root2->left->left = new TreeNode(2);
    root2->left->right = new TreeNode(4);
    root2->left->left->left = new TreeNode(1);
    root2->right = new TreeNode(6);
    run(root2, 3);
    return 0;
}
