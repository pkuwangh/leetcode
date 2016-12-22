/* Given a sorted linked list, delete all nodes that have duplicate numbers,
 * leaving only distinct numbers from the original list.
 *
 * For example,
 * Given 1->2->3->3->4->4->5, return 1->2->5.
 * Given 1->1->1->2->3, return 2->3.
 */

#include <iostream>
#include <memory>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        // since first node can be deleted, create a dummy node
        unique_ptr<ListNode> dummy_head(new ListNode(head->val-1));
        dummy_head->next = head;
        // 2 pointers
        ListNode* prev = dummy_head.get();
        ListNode* curr = head;
        int duplicate_value = 0;
        bool duplicate_valid = false;

        while (curr) {
            if (duplicate_valid && curr->val == duplicate_value) {
                // delete curr
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            } else if (curr->next && curr->next->val == curr->val) {
                // check in duplicate value
                duplicate_value = curr->val;
                duplicate_valid = true;
                // delete curr
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            } else {
                duplicate_valid = false;
                prev = curr;
                curr = curr->next;
            }
        }
        return dummy_head->next;
    }
};

int main() {
    Solution obj;
    auto head = obj.deleteDuplicates(NULL);
    cout << head << endl;
    return 0;
}
