# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def rotateRight(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if k == 0 or not head:
            return head

        length = 0
        link = last_node = head
        while link:
            length += 1
            last_node = link
            link = link.next

        if k % length == 0:
            return head

        new_head = new_tail = head
        for i in range((length - k) % length):
            new_tail = new_head
            new_head = new_head.next
        last_node.next = head
        head = new_head
        new_tail.next = None
        return head
