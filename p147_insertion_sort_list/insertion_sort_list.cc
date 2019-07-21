/* Sort a linked list using insertion sort.
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
    ListNode* insertionSortList(ListNode* head) {
        // create a dummy head
        ListNode* dummy_head = new ListNode(-1);

        while(head) {
            // find the position for cur
            ListNode* cur = head;
            // scan from prev
            ListNode* prev = dummy_head;
            // this should be moved first
            head = head->next;
            // find last node that is smaller than cur
            while (prev->next && prev->next->val < cur->val) {
                prev = prev->next;
            }
            // insert
            cur->next = prev->next;
            prev->next = cur;
        }
        head = dummy_head->next;
        delete dummy_head;
        return head;
    }
};

int main() {
    Solution obj;
    cout << obj.insertionSortList(new ListNode(1))->val << endl;
    return 0;
}
