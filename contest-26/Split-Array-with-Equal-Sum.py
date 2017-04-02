class Solution(object):
    def splitArray(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        preSum = [0]
        for x in nums :
            preSum.append(preSum[-1] + x)
        
        prei = collections.defaultdict(list);
        for i, u in enumerate(preSum) :
            prei[u].append(i)
        
        n = len(nums)
        for j in xrange(3, n) :
            for k in xrange(j+2, n-1) :
                u = preSum[-1] - preSum[k + 1]
                for i in prei[u] :
                    if i >= j - 1 : break
                    if preSum[i] == preSum[j] - preSum[i + 1] == preSum[k] - preSum[j + 1] :
                        return True
        return False
