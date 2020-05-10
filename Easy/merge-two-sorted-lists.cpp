// Problem: https://leetcode.com/problems/merge-two-sorted-lists/
//
// Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
//
// Example:
//
// Input: 1->2->4, 1->3->4
// Output: 1->1->2->3->4->4

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* p = NULL;
        if ((NULL == l1) && (NULL == l2)) {
            return NULL;
        }
        else if ((NULL == l1) && (NULL != l2)) {
            return l2;
        }
        else if ((NULL != l1) && (NULL == l2)) {
            return l1;
        }
        ListNode* pMergedList = NULL;
        if (l1->val < l2->val) {
            pMergedList = l1;
            l1 = l1->next;
        }
        else {                        
            pMergedList = l2;
            l2 = l2->next;
        }
        p = pMergedList;
        while ((l1 != NULL) && (l2 != NULL)) {
            if (l1->val < l2->val) {                
                pMergedList->next = l1;
                l1 = l1->next;                
            }
            else {               
               pMergedList->next = l2;
               l2 = l2->next;
            }
            pMergedList = pMergedList->next;
        }
        if (l1 == NULL){
            pMergedList->next = l2;
        }
        else if (l2 == NULL) {
            pMergedList->next = l1;            
        }
        return p;
    }
};
