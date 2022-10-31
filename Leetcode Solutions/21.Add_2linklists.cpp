/*You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

 

Example 1:


Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
Output: [0]
 

Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.*/

//  Definition for singly-linked list.
#include <bits/stdc++.h> 
using namespace std;
  
  
  
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        
    if(head1 == NULL && head2!= NULL){
        
        return head2;
        
    }else if(head1 != NULL && head2== NULL){
        
        return head1;
        
    }else if(head1==NULL && head2==NULL){
        return NULL;
    }
        
        
    
    ListNode *finalhead = NULL;
    ListNode *finaltail = NULL;
    if (head1->val < head2->val)
    {
        finalhead = head1;
        finaltail = head1;
        head1 = head1->next;
    }
    else
    {
        finalhead = head2;
        finaltail = head2;
        head2 = head2->next;
    }
    while (head1 != NULL && head2 != NULL)
    {

        if (head1->val < head2->val)
        {
            finaltail->next = head1;

            head1 = head1->next;
        }
        else
        {
            finaltail->next = head2;

            head2 = head2->next;
        }
        finaltail = finaltail->next;
    }
    if (head1 == NULL)
    {
        finaltail->next = head2;
    }
    else if (head2 == NULL)
    {
        finaltail->next = head1;
    }

    return finalhead;
    }
};