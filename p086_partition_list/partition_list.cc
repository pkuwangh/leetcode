/* Given a linked list and a value x,
 * partition it such that all nodes less than x come before nodes greater than or equal to x.
 * You should preserve the original relative order of the nodes in each of the two partitions.
 *
 * For example,
 * Given 1->4->3->2->5->2 and x = 3,
 * return 1->2->2->4->3->5.
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
    ListNode* partition(ListNode* head, int x) {
        ListNode *dummy_L = new ListNode(0);
        ListNode *dummy_R = new ListNode(0);
        ListNode *cur_L = dummy_L;
        ListNode *cur_R = dummy_R;
        while (head != NULL) {
            if (head->val < x) {
                cur_L->next = head;
                cur_L = head;
            } else {
                cur_R->next = head;
                cur_R = head;
            }
            head = head->next;
        }
        // connect
        cur_L->next = dummy_R->next;
        // last node
        cur_R->next = NULL;
        // new head
        head = dummy_L->next;
        return head;
    }
};

int main() {
    Solution obj;
    ListNode *head = new ListNode(2);
    head->next = new ListNode(1);
    cout << obj.partition(head, 2) << endl;
    cout << obj.partition(NULL, 0) << endl;
    return 0;
}
