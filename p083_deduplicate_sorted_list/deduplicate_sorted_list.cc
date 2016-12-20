/* Given a sorted linked list, delete all duplicates such that each element appear only once.
 *
 * For example,
 * Given 1->1->2, return 1->2.
 * Given 1->1->2->3->3, return 1->2->3.
 */

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        ListNode* prev = head;
        ListNode* curr = head->next;
        while (curr) {
            if (prev->val == curr->val) {
                prev->next = curr->next;
                curr = curr->next;
            } else {
                prev = prev->next;
                curr = curr->next;
            }
        }
        return head;
    }
};

int main() {
    Solution obj;
    auto head = obj.deleteDuplicates(NULL);
    cout << head << endl;
    return 0;
}
