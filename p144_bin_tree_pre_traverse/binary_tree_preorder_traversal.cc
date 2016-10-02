/* Given a binary tree, return the preorder traversal of its nodes' values.
 *
 * For example:
 * Given binary tree {1,#,2,3},
 *    1
 *     \
 *      2
 *     /
 *    3
 * return [1,2,3].
 */

#include <iostream>
#include <vector>
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        traverse(ans, root);
        return ans;
    }

    void traverse(vector<int> &ans, TreeNode* root) {
        if (root == NULL) {
            return;
        }
        // visit root node first
        ans.push_back(root->val);
        // left tree
        traverse(ans, root->left);
        // right tree
        traverse(ans, root->right);
    }
};

int main() {
    Solution obj;

    TreeNode *n1 = new TreeNode(1);
    TreeNode *n2 = new TreeNode(2);
    TreeNode *n3 = new TreeNode(3);
    n1->right = n2;
    n2->left = n3;

    vector<int> ans = obj.preorderTraversal(n1);

    for (auto &k : ans) {
        cout << k << " ";
    }
    cout << endl;
    return 0;
}
