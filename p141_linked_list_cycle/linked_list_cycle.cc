/* Given a linked list, determine if it has a cycle in it.
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
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) return false;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow) {
                return true;
            }
        }
        return false;
    }
    // actually, fast pointer won't skip the slow pointer
#if 0 
    bool hasCycle(ListNode *head) {
        if (!head) return false;

        ListNode *p = head;
        ListNode *p2 = head->next;
        while (p2) {
            if (p == p2) {
                return true;
            }
            p2 = p2->next;
            if (!p2) {
                break;
            }
            if (p == p2) {
                return true;
            }
            p = p->next;
            p2 = p2->next;
        }
        return false;
    }
#endif
};

int main() {
    Solution obj;
    cout << obj.hasCycle(NULL) << endl;
    return 0;
}
