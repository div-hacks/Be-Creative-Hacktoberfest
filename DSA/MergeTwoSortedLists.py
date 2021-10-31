class Solution(object):
    def mergeTwoLists(self, l1, l2):
        head_ptr = temp_ptr = ListNode(0)
        while l1 or l2:
            if l1 and (not l2 or l1.val <= l2.val):
                temp_ptr.next = ListNode(l1.val)
                l1 = l1.next
            else:
                temp_ptr.next = ListNode(l2.val)
                l2 = l2.next
            temp_ptr = temp_ptr.next
        return head_ptr.next