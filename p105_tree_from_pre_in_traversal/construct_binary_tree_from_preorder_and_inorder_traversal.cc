/* Given preorder and inorder traversal of a tree, construct the binary tree.
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) return NULL;
        return build(preorder, 0, preorder.size(), inorder, 0);
    }

    TreeNode* build(vector<int>& preorder, int pre_start, int size,
                    vector<int>& inorder, int in_start)
    {
        if (size == 0) return NULL;

        TreeNode* root = new TreeNode(preorder.at(pre_start));
        int left_size = 0;
        while (inorder.at(in_start + left_size) != preorder.at(pre_start)) {
            ++ left_size;
        }
        root->left = build(preorder, pre_start+1, left_size, inorder, in_start);
        int right_size = size-1-left_size;
        root->right = build(preorder, pre_start+left_size+1, right_size, inorder, in_start+left_size+1);
        return root;
    }
};

int main() {
    Solution obj;
    vector<int> preorder({1, 2});
    vector<int> inorder({2, 1});
    TreeNode* root = obj.buildTree(preorder, inorder);
    cout << root->val << " ";
    if (root->left) cout << root->left->val << " ";
    if (root->right) cout << root->right->val << " ";
    cout << endl;
    return 0;
}
