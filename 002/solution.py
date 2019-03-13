# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        root = l3 = ListNode(0)
        tmp = 0
        while l1 or l2 or tmp:
            v1, v2 = 0, 0
            if l1:
                v1 = l1.val
                l1 = l1.next
            if l2:
                v2 = l2.val
                l2 = l2.next
            tmp, val = divmod(v1 + v2 + tmp, 10)
            l3.next = ListNode(val)
            l3 = l3.next

        return root.next
