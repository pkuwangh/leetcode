/* Given a linked list, return the node where the cycle begins.
 * If there is no cycle, return null.
 * Note: Do not modify the linked list.
 * Follow up:
 * Can you solve it without using extra space?
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
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) return NULL;
        // use fast & slow pointers
        ListNode *slow = head;
        ListNode *fast = head;
        do {
            if (fast->next == NULL || fast->next->next == NULL) { return NULL; }
            fast = fast->next->next;
            slow = slow->next;
        } while (fast != slow);
        // slow travelled L + offset
        // fast travelled L + n*C + offset = 2 * (L + offset)
        // L = n*C - offset
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};

int main() {
    Solution obj;
    ListNode* head = new ListNode(0);
    ListNode* cur = head;
    for (int i = 1; i < 10; ++i) {
        cur->next = new ListNode(i);
        cur = cur->next;
    }
    cur->next = head->next->next->next->next;   // 4
    cout << (obj.detectCycle(head))->val << endl;
    return 0;
}
