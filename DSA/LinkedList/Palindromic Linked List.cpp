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
private:
    ListNode* reverse(ListNode* head) {
        ListNode *curr = head, *prev = NULL, *nex = head;
        while(nex) {
            nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;            
        }        
        return prev;
    }
    
public:
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        
        ListNode *slow = head, *fast = head;
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Optimal Approach : Space Complexity : O(1)
        
        slow->next = reverse(slow->next);
        ListNode* tmp = slow->next;
        ListNode* it = head;
        while(it != slow->next && tmp) {
            if(it->val != tmp->val) return false;
            tmp = tmp->next;
            it = it->next;
        }
        
        
        // Space Complexity of Below Solution : O(n)
        
//         ListNode *tmp = head;
//         stack<int> st;
//         while(tmp != slow) {
//             st.push(tmp->val);
//             tmp = tmp->next;
//         }
//         if(fast) slow = slow->next;
//         while(slow) {
//             if(st.top() != slow->val) return false;
//             st.pop();
//             slow = slow->next;
//         }
        
//         return st.empty();
        
        return true;
    }
};