/**
 * Given a singly linked list, determine if it is a palindrome.
 * Example 1:
 * Input: 1->2
 * Output: false
 * Example 2:
 * Input: 1->2->2->1
 * Output: true
 * Follow up:
 * Could you do it in O(n) time and O(1) space?
 */

#include <cassert>
#include <cstdint>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <list>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL) return true;
        // first pass, count number of nodes, find tail pointer
        ListNode* tail = NULL;
        int num_nodes = 0;
        ListNode* curr = head;
        while (curr != NULL) {
            ++ num_nodes;
            tail = curr;
            curr = curr->next;
        }
        // second pass, revert 2nd half
        ListNode* prev = NULL;
        curr = head;
        int num = 0;
        while (curr != NULL) {
            if (num > num_nodes/2) {
                // revert
                ListNode* next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            } else {
                // simply going forward
                prev = curr;
                curr = curr->next;
            }
            ++ num;
        }
        // verify palindrome
        bool is_palindrome = true;
        ListNode* left = head;
        ListNode* right = tail;
        while (left != right) {
            if (left->val != right->val) {
                is_palindrome = false;
            }
            if (left->next == right || right->next == left) {
                break;
            }
            left = left->next;
            right = right->next;
        }
        // 3rd pass, revert 2nd half back
        prev = NULL;
        curr = tail;
        while (curr->next != prev) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return is_palindrome;
    }
};

int main() {
    Solution obj;
    auto run = [&](ListNode* head) ->void {
        ListNode* curr = head;
        while (curr != NULL) {
            cout << curr->val << " ";
            curr = curr->next;
        }
        cout << endl;
        cout << obj.isPalindrome(head) << endl;
        curr = head;
        while (curr != NULL) {
            cout << curr->val << " ";
            curr = curr->next;
        }
        cout << endl;
    };
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);
    run(head);
    return 0;
}
