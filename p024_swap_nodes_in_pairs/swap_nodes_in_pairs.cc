/* Given a linked list, swap every two adjacent nodes and return its head.
 * For example,
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
 * Your algorithm should use only constant space.
 * You may not modify the values in the list, only nodes itself can be changed.
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
    ListNode* swapPairs(ListNode* head) {
        // create a dummy head
        unique_ptr<ListNode> dummy(new ListNode(0));
        dummy->next = head;
        // pointers
        ListNode* prev = dummy.get();
        ListNode* cur = head;
        while (cur && cur->next) {
            // swap
            prev->next = cur->next;
            cur->next = cur->next->next;
            prev->next->next = cur;
            // forward
            prev = cur;
            cur = cur->next;
        }

        return dummy->next;
    }
};

int main() {
    Solution obj;
    obj.swapPairs(NULL);
    return 0;
}
