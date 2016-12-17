/* Given an array where elements are sorted in ascending order,
 * convert it to a height balanced BST.
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0) {
            return NULL;
        } else {
            return constructBST(nums, 0, nums.size()-1);
        }
    }

    TreeNode* constructBST(vector<int>& nums, int left, int right) {
        if (left > right) {
            return NULL;
        } else if (left == right) {
            return (new TreeNode(nums[left]));
        } else {
            int mid = (left + right) / 2;
            TreeNode *root = new TreeNode(nums[mid]);
            root->left = constructBST(nums, left, mid-1);
            root->right = constructBST(nums, mid+1, right);
            return root;
        }
    }

    TreeNode* sortedArrayToBSTHelper(vector<int> nums) {
        return sortedArrayToBST(nums);
    }
};

int main() {
    Solution obj;
    TreeNode* root = obj.sortedArrayToBSTHelper({0, 1, 2});
    cout << root->left->val << " " << root->val << " " << root->right->val << endl;
    return 0;
}
