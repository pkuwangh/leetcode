/* Given a binary tree, return the inorder traversal of its nodes' values.
 *
 * For example:
 * Given binary tree [1,null,2,3],
 *    1
 *     \
 *      2
 *     /
 *    3
 * return [1,3,2].
 *
 * Note: Recursive solution is trivial, could you do it iteratively?
 *
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        traverse(ans, root);
        return ans;
    }

    void traverse(vector<int> &ans, TreeNode* root) {
        if (root == NULL) {
            return;
        }
        // left child tree
        traverse(ans, root->left);
        // visit root
        ans.push_back(root->val);
        // right child tree
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

    vector<int> ans = obj.inorderTraversal(n1);

    for (auto &k : ans) {
        cout << k << " ";
    }
    cout << endl;
    return 0;
}
