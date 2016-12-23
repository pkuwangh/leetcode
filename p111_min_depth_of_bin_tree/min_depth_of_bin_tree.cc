/* Given a binary tree, find its minimum depth.
 * The minimum depth is the number of nodes along the shortest path from the root node
 * down to the nearest leaf node.
 */

#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;
        // BFS
        queue<TreeNode*> to_visit;
        to_visit.push(root);
        int num_next = 1;
        int num_cur = 0;
        int depth = 0;
        while (num_next > 0) {
            ++ depth;
            num_cur = num_next;
            num_next = 0;
            while (num_cur > 0) {
                TreeNode* node = to_visit.front();
                to_visit.pop();
                -- num_cur;
                if (node->left == NULL && node->right == NULL) {
                    // reach leaf
                    num_next = 0;
                    break;
                }

                if (node->left) {
                    to_visit.push(node->left);
                    ++ num_next;
                }
                if (node->right) {
                    to_visit.push(node->right);
                    ++ num_next;
                }
            }
        }
        return depth;
    }
};

int main() {
    Solution obj;
    cout << obj.minDepth(NULL) << endl;
    TreeNode* root = new TreeNode(0);
    cout << obj.minDepth(root) << endl;
    delete root;
    return 0;
}
