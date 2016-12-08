/* Two elements of a binary search tree (BST) are swapped by mistake.
 * Recover the tree without changing its structure.
 *
 * Note:
 * A solution using O(n) space is pretty straight forward.
 * Could you devise a constant space solution?
 */

// Definition for a binary tree node.
#include <iostream>
#include <list>
#include <cassert>
using namespace std;

#define DEBUG

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
    void recoverTree(TreeNode* root) {
        TreeNode* s1 = NULL;
        TreeNode* s2 = NULL;
        TreeNode* last = NULL;
        inOrderTraversal(root, last, s1, s2);
        int temp = s1->val;
        s1->val = s2->val;
        s2->val = temp;
    }

    void inOrderTraversal(TreeNode* root, TreeNode* &last, TreeNode* &s1, TreeNode* &s2) {
        if (root == NULL) return;

        inOrderTraversal(root->left, last, s1, s2);
        if (last != NULL && last->val > root->val) {
            if (s1 == NULL) {
                s1 = last;
                s2 = root;
            } else {
                s2 = root;
            }
        }
        last = root;
        inOrderTraversal(root->right, last, s1, s2);
    }
};

int main() {
    Solution obj;

    TreeNode *n1 = new TreeNode(1);
    TreeNode *n2 = new TreeNode(2);
    TreeNode *n3 = new TreeNode(3);
    n1->left = n2;
    n1->right = n3;

    obj.recoverTree(n1);

    return 0;
}
