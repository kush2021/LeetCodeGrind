/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        /* Add the numbers. */
        ListNode * ans = new ListNode();
        ListNode * curr = ans;
        int sum = 0, carry = 0;
        while (l1 != NULL && l2 != NULL) {
            curr -> next = new ListNode();
            curr = curr -> next;
            sum = l1 -> val + l2 -> val + carry;
            carry = 0;
            if (sum >= 10) {
                carry = sum / 10;
                sum %= 10;
            }
            curr -> val = sum;
            l1 = l1 -> next;
            l2 = l2 -> next;
        }
        while (l1 != NULL) {
            curr -> next = new ListNode();
            curr = curr -> next;
            sum = l1 -> val + carry;
            carry = 0;
            if (sum >= 10) {
                carry = sum / 10;
                sum %= 10;
            }
            curr -> val = sum;
            l1 = l1 -> next;
        }
        while (l2 != NULL) {
            curr -> next = new ListNode();
            curr = curr -> next;
            sum = l2 -> val + carry;
            carry = 0;
            if (sum >= 10) {
                carry = sum / 10;
                sum %= 10;
            }
            curr -> val = sum;
            l2 = l2 -> next;
        }
        if (carry) {
            curr -> next = new ListNode();
            curr = curr -> next;
            curr -> val = carry;
        }
        return ans -> next; 
    }
};
// @lc code=end