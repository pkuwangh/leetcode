/* Reverse a singly linked list.
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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) {
            return head;
        }
        ListNode *prev = NULL;
        ListNode *cur  = head;
        // scan through the list
        while (cur != NULL) {
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
};

int main() {
    auto displayList = [](ListNode *head) {
        while (head != NULL) {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    };

    int n = 8;
    ListNode *head = new ListNode(n);
    ListNode *cur = head;
    for (int i = n-1; i > 0; --i) {
        cur->next = new ListNode(i);
        cur = cur->next;
    }

    displayList(head);

    Solution obj;
    displayList(obj.reverseList(head));

    return 0;
}
