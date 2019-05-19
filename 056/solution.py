class Solution(object):
    def merge(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: List[List[int]]
        """
        res = []
        intervals.sort(key = lambda x: x[0])
        for interval in intervals:
            if res and interval[0] <= res[-1][1]:
                res[-1][1] = max(interval[1], res[-1][1])
            else:
                res.append(interval)
        return res
