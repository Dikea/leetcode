import heapq

class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        h = []
        ret = head = ListNode(0)
        lists_len = len(lists)
        for i in range(lists_len):
            if lists[i]:
                heapq.heappush(h, (lists[i].val, i))
                lists[i] = lists[i].next
        while h:
            val, id_ = heapq.heappop(h)
            node = ListNode(val)
            ret.next = node
            ret = ret.next
            if lists[id_]:
                heapq.heappush(h, (lists[id_].val, id_))
                lists[id_] = lists[id_].next
        return head.next
