/* Sort a linked list in O(n log n) time using constant space complexity.
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

// merge sort
class Solution {
  public:
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            // 1 node left or initial list if NULL
            return head;
        }
 
        ListNode *mid = head;
        ListNode *cur = head->next;
        // only two nodes left, mid points to 1st one; break into 1:1
        // only three nodes left, mid points to 2nd one; break into 2:1
        while (cur != NULL && cur->next != NULL) {
            mid = mid->next;
            cur = cur->next->next;
        }

        // sort right half
        ListNode *right = sortList(mid->next);
        // sort left half
        mid->next = NULL;
        ListNode *left = sortList(head);
        // merge
        return mergeList(left, right);
    }

    ListNode* mergeList(ListNode *l1, ListNode *l2) {
        // create a dummy head
        ListNode *dummy = new ListNode(-1);
        ListNode *cur = dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if (l1) {
            cur->next = l1;
        } else {
            cur->next = l2;
        }
        cur = dummy->next;
        delete dummy;
        return cur;
    }
};

int main() {
    Solution obj;
 
    auto displayList = [](const ListNode *head) {
        while (head != NULL) {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    };

    int n = 9;
    ListNode *head = new ListNode(n);
    ListNode *cur = head;
    for (int i = n-1; i >0; --i) {
        cur->next = new ListNode(i);
        cur = cur->next;
    }

    displayList(head);
    displayList( obj.sortList(head) );
}
