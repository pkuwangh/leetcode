/* Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
 * 
 * Example:
 * 
 * Input: [1,2,3,null,5,null,4]
 * Output: [1, 3, 4]
 * Explanation:
 * 
 *       1            <---
 *     /   \
 *    2     3         <---
 *     \     \
 *      5     4       <---
 */

#include <vector>
#include <deque>
#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
    vector<int> rightSideView(TreeNode* root) {
        std::vector<int> right_view;
        if (root == nullptr) return right_view;
        // BFS
        deque<TreeNode*> bfs_q;
        bfs_q.push_back(root);
        bfs_q.push_back(nullptr);
        int last_in_level = 0;
        int num_in_next_level = 0;
        while (!bfs_q.empty()) {
            TreeNode* node = bfs_q.front();
            bfs_q.pop_front();
            if (node == nullptr) {
                right_view.emplace_back(last_in_level);
                if (num_in_next_level > 0) {
                    bfs_q.push_back(nullptr);
                    num_in_next_level = 0;
                }
            } else {
                last_in_level = node->val;
                if (node->left != nullptr) {
                    bfs_q.push_back(node->left);
                    ++ num_in_next_level;
                }
                if (node->right != nullptr) {
                    bfs_q.push_back(node->right);
                    ++ num_in_next_level;
                }
            }
        }
        return right_view;
    }
};

int main() {
    Solution obj;
    TreeNode* root = new TreeNode(1);
    vector<int> res1 = obj.rightSideView(root);
    for (auto& x : res1) {
        cout << x << " ";
    }
    cout << endl;
    root->left  = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);
    vector<int> res2 = obj.rightSideView(root);
    for (auto& x : res2) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
