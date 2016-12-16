/* Write a program to find the node at which
 * the intersection of two singly linked lists begins.
 *
 * For example, the following two linked lists:
 *
 * A:       a1 → a2
 *                 ↘
 *                   c1 → c2 → c3
 *                 ↗            
 * B:  b1 → b2 → b3
 * begin to intersect at node c1.
 *
 * Notes:
 * If the two linked lists have no intersection at all, return null.
 * The linked lists must retain their original structure after the function returns.
 * You may assume there are no cycles anywhere in the entire linked structure.
 * Your code should preferably run in O(n) time and use only O(1) memory.
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) return NULL;
        // get the length
        int lenA = 0;
        int lenB = 0;
        ListNode *pA = headA;
        ListNode *pB = headB;
        while (pA->next != NULL) {
            ++ lenA;
            pA = pA->next;
        }
        while (pB->next != NULL) {
            ++ lenB;
            pB = pB->next;
        }
        // should converge if intersect
        if (pA != pB) return NULL;
        // find the intersection point based on the lengths
        if (lenA < lenB) {
            // forward B
            for (int i = 0; i < lenB - lenA; ++i) {
                headB = headB->next;
            }
        } else {
            // forward A
            for (int i = 0; i < lenA - lenB; ++i) {
                headA = headA->next;
            }
        }
        while (headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};

int main()
{
    Solution obj;
    obj.getIntersectionNode(NULL, NULL);

    return 0;
}
