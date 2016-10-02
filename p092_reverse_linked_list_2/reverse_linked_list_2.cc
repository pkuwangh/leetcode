/* Reverse a linked list from position m to n. Do it in-place and in one-pass.
 * For example:
 * Given  1->2->3->4->5->NULL, m = 2 and n = 4,
 * return 1->4->3->2->5->NULL.
 *
 * Note:
 * Given m, n satisfy the following condition:
 * 1 ≤ m ≤ n ≤ length of list.
 */

#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == NULL || head->next == NULL || m == n) {
            return head;
        }
        // head could change; create a dummy node
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        // find connection points
        ListNode *left_out = dummy;
        ListNode *left_in  = head;
        // scan one-pass
        ListNode *prev = dummy;
        ListNode *cur  = head;
        int num = 0;
        while (cur != NULL) {
            ++ num;
            if (num <= m) {
                if (num == m) {
                    left_out = prev;
                    left_in  = cur;
                }
                cur = cur->next;
                prev = prev->next;
            } else if (num > m && num < n) {
                ListNode *next = cur->next;
                cur->next = prev;
                prev = cur;
                cur = next;
            } else if (num == n) {
                // make connection and done
                left_out->next = cur;
                left_in->next = cur->next;
                cur->next = prev;
                break;
            } else {
                return NULL;  // invalid input
            }
        }
        cur = dummy->next;
        delete dummy;
        return cur;
    }
};

int main() {
    Solution obj;

    auto displayList = [](ListNode *head) {
        while (head != NULL) {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    };

    int l = 8;
    ListNode *head = new ListNode(l);
    ListNode *cur = head;
    for (int i = l-1; i > 0; --i) {
        cur->next = new ListNode(i);
        cur = cur->next;
    }

    displayList(head);
//    displayList(obj.reverseBetween(head, 2, 5));
//    displayList(obj.reverseBetween(head, 2, 8));
    displayList(obj.reverseBetween(head, 1, 5));

    return 0;
}
