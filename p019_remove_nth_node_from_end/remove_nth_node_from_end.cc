/* Given a linked list, remove the nth node from the end of list and return its head.
 * For example,
 * Given linked list: 1->2->3->4->5, and n = 2.
 *
 * After removing the second node from the end, the linked list becomes 1->2->3->5.
 * Note:
 * Given n will always be valid.
 * Try to do this in one pass.
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* fast = dummy;
        ListNode* slow = dummy;

        int distance = 0;
        while (fast != NULL) {
            if (distance == n+1) {
                slow = slow->next;
            } else {
                ++ distance;
            }
            fast = fast->next;
        }

        fast = slow->next;
        slow->next = fast->next;

        fast->next = NULL;
        delete fast;

        return dummy->next;
    }
};

int main()
{
    Solution obj;

    auto print_list = [](ListNode *head)->void {
        while (head != NULL) {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    };

    ListNode *head = new ListNode(1);
    ListNode *cur = head;
    for (int i = 2; i < 6; ++i) {
        cur->next = new ListNode(i);
        cur = cur->next;
    }

    print_list(head);

    print_list( obj.removeNthFromEnd(head, 2) );
    print_list( obj.removeNthFromEnd(head, 4) );

    return 0;
}
