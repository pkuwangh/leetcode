/* A linked list is given such that each node contains an additional random pointer
 * which could point to any node in the list or null.
 * Return a deep copy of the list.
 */

#include <iostream>
#include <unordered_map>
using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
  public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL) return NULL;
        // build a hash map
        unordered_map<RandomListNode*, RandomListNode*> node_ht;
        // two-pass
        RandomListNode *new_head = new RandomListNode(head->label);
        node_ht[head] = new_head;
        RandomListNode *cur = head;
        while (cur->next != NULL) {
            node_ht[cur]->next = new RandomListNode(cur->next->label);
            node_ht[cur->next] = node_ht[cur]->next;
            cur = cur->next;
        }
        cur = head;
        while (cur != NULL) {
            node_ht[cur]->random = node_ht[cur->random];
            cur = cur->next;
        }
        return new_head;
    }
};

int main() {
    Solution obj;
    cout << obj.copyRandomList(NULL) << endl;
    return 0;
}
