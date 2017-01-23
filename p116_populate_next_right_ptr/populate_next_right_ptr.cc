/* Given a binary tree
 *     struct TreeLinkNode {
 *         TreeLinkNode *left;
 *         TreeLinkNode *right;
 *         TreeLinkNode *next;
 *     }
 * Populate each next pointer to point to its next right node.
 * If there is no next right node, the next pointer should be set to NULL.
 * Initially, all next pointers are set to NULL.
 * Note:
 * You may only use constant extra space.
 * You may assume that it is a perfect binary tree
 * (ie, all leaves are at the same level, and every parent has two children).
 * For example,
 * Given the following perfect binary tree,
 *         1
 *        /  \
 *       2    3
 *      / \  / \
 *     4  5  6  7
 * After calling your function, the tree should look like:
 *         1 -> NULL
 *        /  \
 *       2 -> 3 -> NULL
 *      / \  / \
 *     4->5->6->7 -> NULL
 */
#include <iostream>
#include <queue>
using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
  public:
    void connect(TreeLinkNode *root) {
        if (root == NULL) return;
        queue<TreeLinkNode*> nodes;
        nodes.push(root);
        int cur = 0;
        int next = 1;
        while (next > 0) {
            cur = next;
            next = 0;
            while (cur > 0) {
                --cur;
                TreeLinkNode* cur_node = nodes.front();
                nodes.pop();
                if (cur > 0) {
                    cur_node->next = nodes.front();
                }
                if (cur_node->left) {
                    ++next;
                    nodes.push(cur_node->left);
                }
                if (cur_node->right) {
                    ++next;
                    nodes.push(cur_node->right);
                }
            }
        }
    }
};

int main() {
    Solution obj;
    obj.connect(NULL);
    return 0;
}
