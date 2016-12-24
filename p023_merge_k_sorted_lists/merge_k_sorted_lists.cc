/* M
 * Analyze and describe its complexity.
 */

#include <iostream>
#include <vector>
#include <queue>
#include <memory>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // define a priority queue
        auto comp = [](ListNode* &e1, ListNode* &e2)->bool {
            return e1->val > e2->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> nodes(comp);

        for (unsigned int i = 0; i < lists.size(); ++i) {
            ListNode* head = lists[i];
            while (head != NULL) {
                nodes.push(head);
                head = head->next;
            }
        }
        // pop
        ListNode* head = NULL;
        if (!nodes.empty()) {
            head = nodes.top();
            nodes.pop();
            ListNode *cur = head;
            while (!nodes.empty()) {
                cur->next = nodes.top();
                nodes.pop();
                cur = cur->next;
            }
            cur->next = NULL;
        }
        return head;
    }
};

int main() {
    Solution obj;
    vector<ListNode*> lists(1, NULL);
    obj.mergeKLists(lists);
    return 0;
}
