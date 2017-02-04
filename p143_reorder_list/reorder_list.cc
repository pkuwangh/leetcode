/* Given a singly linked list L: L0→L1→…→Ln-1→Ln,
 * reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
 * You must do this in-place without altering the nodes' values.
 *
 * For example,
 * Given {1,2,3,4}, reorder it to {1,4,2,3}.
*/

#include <iostream>
#include <deque>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    void reorderList(ListNode* head) {
        if (head == NULL) return;
        deque<ListNode*> dq;
        ListNode *cur = head;
        while (cur && cur->next) {
            cur = cur->next;
            dq.push_back(cur);
        }
        cur = head;
        while(!dq.empty()) {
            cur->next = dq.back();
            dq.pop_back();
            cur = cur->next;
            if (!dq.empty()) {
                cur->next = dq.front();
                dq.pop_front();
                cur = cur->next;
            }
        }
        cur->next = NULL;
    }
};

int main() {
    Solution obj;
    ListNode* head = new ListNode(1);
    ListNode* cur = head;
    for (int i = 2; i < 7; ++i) {
        cur->next = new ListNode(i);
        cur = cur->next;
    }
    auto printList = [](ListNode* head) {
        while (head) {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    };
    printList(head);
    obj.reorderList(head);
    printList(head);
    return 0;
}
