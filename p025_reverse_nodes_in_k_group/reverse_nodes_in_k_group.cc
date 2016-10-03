/* Given a linked list, reverse the nodes of a linked list k at a time
 * and return its modified list.
 *
 * If the number of nodes is not a multiple of k
 * then left-out nodes in the end should remain as it is.
 *
 * You may not alter the values in the nodes, only nodes itself may be changed.
 * Only constant memory is allowed.
 *
 * For example,
 * Given this linked list: 1->2->3->4->5
 * For k = 2, you should return: 2->1->4->3->5
 * For k = 3, you should return: 3->2->1->4->5
 */

#include <iostream>
#include <cassert>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k < 2) {
            return head;
        }
        // create a dummy head
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        // have a node pointing to the connection node
        ListNode *p = dummy;
        while (p->next && p->next->next) {
            ListNode *prev = p->next;
            ListNode *curr = prev->next;
            // reverse
            int n = 0;
            while (curr != NULL && n < k-1) {
                ListNode *next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
                ++ n;
            }

            if (n == k-1) {
                // reversed k nodes; make connections
                ListNode *temp = p->next;   // last node in last group
                p->next = prev;
                temp->next = curr;
                p = temp;
            } else {
                // need reverse back
                curr = prev;
                prev = NULL;
                while (curr != p->next) {
                    ListNode *next = curr->next;
                    curr->next = prev;
                    prev = curr;
                    curr = next;
                }
                break;
            }
        }
        // return
        head = dummy->next;
        delete dummy;
        return head;
    }
};

int main() {
    Solution obj;

    auto run = [&](int n)->void {
        ListNode *dummy = new ListNode(-1);
        ListNode *curr = dummy;
        for (int i = 0; i < n; ++i) {
            curr->next = new ListNode(i);
            curr = curr->next;
        }
        ListNode *head = dummy->next;
        head = obj.reverseKGroup(head, 3);
        delete dummy;
        while (head != NULL) {
            curr = head;
            cout << head->val << " -> ";
            head = head->next;
            delete curr;
        }
        cout << endl;
    };

    run(8);

    return 0;
}
