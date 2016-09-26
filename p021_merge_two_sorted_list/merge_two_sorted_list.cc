/* Merge two sorted linked lists and return it as a new list.
 * The new list should be made by splicing together the nodes of the first two lists.
 */

#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// create a dummy head
class Solution {
  public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dummy_head = new ListNode(-1);
        ListNode *cur = dummy_head;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        ListNode *l12 = (l1 != NULL) ? l1 : l2;
        while (l12 != NULL) {
            cur->next = l12;
            l12 = l12->next;
            cur = cur->next;
        }
        cur = dummy_head->next;
        delete dummy_head;
        return cur;
    }

#if 0
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *res = NULL;
        ListNode *cur = NULL;
        ListNode *temp = NULL;
        while (l1 != NULL || l2 != NULL) {
            if (l1 != NULL && l2 != NULL) {
                if (l1->val < l2->val) {
                    temp = l1;
                    l1 = l1->next;
                } else {
                    temp = l2;
                    l2 = l2->next;
                }
            } else if (l1 != NULL) {
                temp = l1;
                l1 = l1->next;
            } else {
                temp = l2;
                l2 = l2->next;
            }

            if (res == NULL) {
                res = temp;
                cur = temp;
            } else {
                cur->next = temp;
                cur = cur->next;
            }
        }
        return res;
    }
#endif
};

int main() {
    Solution obj;

    obj.mergeTwoLists(NULL, NULL);

    return 0;
}
