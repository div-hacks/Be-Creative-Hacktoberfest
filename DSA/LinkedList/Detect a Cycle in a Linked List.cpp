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
    bool hasCycle(ListNode *head) {
//         unordered_map<ListNode*, bool> mp;
        
//         ListNode* root = head;
        
//         while(root) {
//             if(mp[root]) return true;
//             else mp[root] = 1;
//             root = root->next;
//         }
        if(!head) return false;
        ListNode *slow = head, *fast = head;
        do {
            if(!slow->next) return false;
            slow = slow->next;
            fast = fast->next->next;
            
        } while(fast && fast->next && slow != fast);
        
        return slow == fast;
    }
};