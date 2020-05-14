// Problem: https://leetcode.com/problems/swap-nodes-in-pairs/
//
// Given a linked list, swap every two adjacent nodes and return its head.
//
// You may not modify the values in the list's nodes, only nodes itself may be changed. 
//
// Example:
//
// Given 1->2->3->4, you should return the list as 2->1->4->3.Given a linked list, swap every two adjacent nodes and return its head.
//
// You may not modify the values in the list's nodes, only nodes itself may be changed.
//
// Example:
//
// Given 1->2->3->4, you should return the list as 2->1->4->3.

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
    ListNode* swapPairs(ListNode* head) {
        ListNode* pre = new ListNode(0);
        pre->next = head;
        ListNode* cur = pre;
        while (cur->next && cur->next->next){
            ListNode* first = cur->next;
            ListNode* third = cur->next->next->next;
            cur->next = first->next;
            cur->next->next = first;
            first->next = third;
            cur = first;
        }
        return pre->next;
    }
};
