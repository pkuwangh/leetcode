/* R
 * Example
 * Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
 * Return: 1 --> 2 --> 3 --> 4 --> 5
 */

#include <iostream>
#include <memory>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    ListNode* removeElements(ListNode* head, int val) {
        unique_ptr<ListNode> dummy(new ListNode(0));
        dummy->next = head;
        ListNode* cur = dummy.get();
        while(cur && cur->next) {
            if (cur->next->val == val) {
                ListNode *to_del = cur->next;
                cur->next = cur->next->next;
                delete to_del;
            } else {
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};

int main() {
    Solution obj;
    ListNode* head = new ListNode(1);
    cout << obj.removeElements(NULL, 0) << endl;
    cout << obj.removeElements(head, 1) << endl;
    return 0;
}
