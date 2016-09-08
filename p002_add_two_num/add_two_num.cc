/*
 * You are given two linked lists representing two non-negative numbers.
 * The digits are stored in reverse order and each of their nodes contain a single digit.
 * Add the two numbers and return it as a linked list.
 * 
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 */

/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>
#include <initializer_list>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
#if 0
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *res = NULL;
        ListNode *cur = NULL;
        int carry = 0;
        while (l1 && l2) {
            int sum = l1->val + l2->val + carry;
            carry = sum / 10;
            sum = sum % 10;
            ListNode *node = new ListNode(sum);
            if (res == NULL) {
                res = node;
            } else {
                cur->next = node;
            }
            cur = node;
            l1 = l1->next;
            l2 = l2->next;
        }

        auto addCarry = [&cur, &res, &carry](ListNode *l)->void {
            while (l) {
                int sum = l->val + carry;
                carry = sum / 10;
                sum = sum % 10;
                ListNode * node = new ListNode(sum);
                if (res == NULL) {
                    res = node;
                } else {
                    cur->next = node;
                }
                cur = node;
                l = l->next;
            }
        };

        addCarry(l1);
        addCarry(l2);

        if (carry > 0) {
            ListNode * node = new ListNode(carry);
            cur->next = node;
        }

        return res;
    }
#endif

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *res = NULL;
        ListNode *cur = NULL;
        int carry = 0;
        while (l1 || l2 || carry > 0) {
            int sum = carry;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            carry = sum / 10;
            sum = sum % 10;

            ListNode *node = new ListNode(sum);
            if (res == NULL) {
                res = node;
            } else {
                cur->next = node;
            }
            cur = node;
        }
        return res;
    }

};

int main()
{
    auto init_list = [](std::initializer_list<int> vals)->ListNode* {
            ListNode* res = NULL;
            ListNode* cur = NULL;
            for (auto val : vals) {
                ListNode *node = new ListNode(val);
                if (res == NULL) {
                    res = node;
                } else {
                    cur->next = node;
                }
                cur = node;
            }
            return res;
    };

    auto print_list = [](ListNode* l)->void {
        while (l != NULL) {
            std::cout << l->val << " ";
            l = l->next;
        }
        std::cout << std::endl;
    };

    Solution obj;

    //
    ListNode * l1a = init_list({2, 4, 3});
    ListNode * l1b = init_list({5, 6, 4});
    print_list(l1a);
    print_list(l1b);

    ListNode * sum1 = obj.addTwoNumbers(l1a, l1b);
    print_list(sum1);

    //
    ListNode * l2a = init_list({2, 4, 3});
    ListNode * l2b = init_list({5, 6, 4, 1});
    print_list(l2a);
    print_list(l2b);

    ListNode * sum2 = obj.addTwoNumbers(l2a, l2b);
    print_list(sum2);

    //
    ListNode * l3a = init_list({2, 4, 3});
    ListNode * l3b = init_list({5, 6, 6, 9});
    print_list(l3a);
    print_list(l3b);

    ListNode * sum3 = obj.addTwoNumbers(l3a, l3b);
    print_list(sum3);

    return 0;
}
