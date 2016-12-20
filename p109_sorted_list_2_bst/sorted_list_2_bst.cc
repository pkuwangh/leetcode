/* Given a singly linked list where elements are sorted in ascending order,
 * convert it to a height balanced BST.
*/

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
    TreeNode* sortedListToBST(ListNode* head) {
        int len = 0;
        ListNode* cur = head;
        while (cur) {
            ++ len;
            cur = cur->next;
        }
        return sortedListToBST(head, 0, len-1);
    }

    TreeNode* sortedListToBST(ListNode* & head, int start, int end) {
        if (start > end) return NULL;
        int mid = (start + end) / 2;
        TreeNode* leftChild = sortedListToBST(head, start, mid-1);
        // head has been moved to mid point
        TreeNode* root = new TreeNode(head->val);
        head = head->next;
        TreeNode* rightChild = sortedListToBST(head, mid+1, end);
        root->left = leftChild;
        root->right = rightChild;
        return root;
    }
};

int main() {
    Solution obj;
    TreeNode* root = obj.sortedListToBST(NULL);
    cout << root << endl;
    return 0;
}
