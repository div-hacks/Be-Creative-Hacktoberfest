/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    /* 
    Approach:

It is based on the concept of difference of length method which requires various steps to work on it. 
Using the same concept of difference of length, a different approach can be implemented. The process is as follows:-

    1. Take two temporary nodes for each list. 
    2. Point each to the head of the lists.
    3. Start iterating over both the lists simultaneously. And if anyone becomes null, point them to the head of the opposite lists and continue iterating until the two iterating nodes points to the same node.
    */
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return NULL;
        ListNode *l1 = headA, *l2 = headB;
        while(l1 != l2) {
            l1 = !l1 ? headB : l1->next;
            l2 = !l2 ? headA : l2->next;
        }
        
        return l1;
    }
};