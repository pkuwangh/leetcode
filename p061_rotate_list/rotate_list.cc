/* Given a list, rotate the list to the right by k places, where k is non-negative.
 *
 * For example:
 * Given 1->2->3->4->5->NULL and k = 2,
 * return 4->5->1->2->3->NULL.
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || k < 0) return head;

        // find the length;
        ListNode* cur = head;
        int length = 1;
        while (cur->next != NULL) {
            ++ length;
            cur = cur->next;
        }
        // connect tail to head
        cur->next = head;
        // find new tail
        k = length - k % length;
        while (k > 0) {
            --k;
            cur = cur->next;
        }
        // break
        head = cur->next;
        cur->next = NULL;
        return head;
    }
};

int main() {
    Solution obj;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    auto rotated = obj.rotateRight(head, 2);
    while (rotated != NULL) {
        cout << rotated->val << " -> ";
        rotated = rotated->next;
    }
    cout << "NULL" << endl;
    return 0;
}
