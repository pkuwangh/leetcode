/* Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1...n.
 *
 * For example,
 * Given n = 3, your program should return all 5 unique BST's shown below.
 *    1         3     3      2      1
 *     \       /     /      / \      \
 *      3     2     1      1   3      2
 *     /     /       \                 \
 *    2     1         2                 3
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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0)
            return vector<TreeNode*>(0);
        else
            return genBST(1, n);
    }

    vector<TreeNode*> genBST(int low, int high) {
        vector<TreeNode*> sols;
        if (low > high) {
            sols.push_back(NULL);
            return sols;
        }

        for (int i = low; i <= high; ++i) {
            auto left_trees = genBST(low, i-1);
            auto right_trees = genBST(i+1, high);
            for (auto &left : left_trees) {
                for (auto &right : right_trees) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    sols.push_back(root);
                }
            }
        }
        return sols;
    }
};

int main() {
    Solution obj;
    cout << obj.generateTrees(3).size() << endl;
    return 0;
}
