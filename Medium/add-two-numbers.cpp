// Problem: https://leetcode.com/problems/add-two-numbers/
//
// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
//
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.
//
// Example:
//
// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8
// Explanation: 342 + 465 = 807.

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
    ListNode *createNode(int val) {
        return new ListNode(val);
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *result = NULL;
        if (!l1 || !l2)	return result;
        bool carry = 0;
        ListNode *retVal = createNode(0);
        result = retVal;
        while (1) {
            int val1 = 0;
            int val2 = 0;

            if (l1)	val1 = l1->val;
            if (l2)	val2 = l2->val;

            int sum = val1 + val2 + carry;
            carry = (sum >= 10);
            int digit = sum % 10;

            result->val = digit;
            if (l1)	l1 = l1->next;
            if (l2)	l2 = l2->next;

            if (!l1 && !l2 && !carry)
                break;

            // More to add.
            result->next = createNode(0);
            result = result->next;
        }

        return retVal;
    }
};
