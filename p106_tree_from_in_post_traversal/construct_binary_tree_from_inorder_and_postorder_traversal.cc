/* Given inorder and postorder traversal of a tree, construct the binary tree.
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0) return NULL;
        return build(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }

    TreeNode* build(vector<int>& inorder, int in_start, int in_end,
                    vector<int>& postorder, int post_start, int post_end)
    {
        if (in_start > in_end) return NULL;
        TreeNode* root = new TreeNode(postorder.at(post_end));
        int left_size = 0;
        while (inorder.at(in_start+left_size) != root->val) {
            ++ left_size;
        }
        root->left = build(inorder, in_start, in_start+left_size-1,
                           postorder, post_start, post_start+left_size-1);
        root->right = build(inorder, in_start+left_size+1, in_end,
                            postorder, post_start+left_size, post_end-1);
        return root;
    }
};

int main() {
    Solution obj;
    vector<int> inorder({2, 1, 3});
    vector<int> postorder({2, 3, 1});
    TreeNode* root = obj.buildTree(inorder, postorder);
    cout << root->val << " ";
    if (root->left) cout << root->left->val << " ";
    if (root->right) cout << root->right->val << " ";
    cout << endl;
    return 0;
}
