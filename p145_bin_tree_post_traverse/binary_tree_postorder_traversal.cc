/* Given a binary tree, return the postorder traversal of its nodes' values.
 *
 * For example:
 * Given binary tree {1,#,2,3},
 *    1
 *     \
 *      2
 *     /
 *    3
 * return [3,2,1].
 * Note: Recursive solution is trivial, could you do it iteratively?
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        traverse(ans, root);
        return ans;
    }

    void traverse(vector<int> &ans, TreeNode* root) {
        if (root == NULL) {
            return;
        }
        // left tree
        traverse(ans, root->left);
        // right tree
        traverse(ans, root->right);
        // visit root node
        ans.push_back(root->val);
    }
};

int main() {
    Solution obj;

    TreeNode *n1 = new TreeNode(1);
    TreeNode *n2 = new TreeNode(2);
    TreeNode *n3 = new TreeNode(3);
    n1->right = n2;
    n2->left = n3;

    vector<int> ans = obj.postorderTraversal(n1);

    for (auto &k : ans) {
        cout << k << " ";
    }
    cout << endl;
    return 0;
}
