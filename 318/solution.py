class Solution(object):
    def maxProduct(self, words):
        """
        :type words: List[str]
        :rtype: int
        """
        ret = 0
        nums = []
        for word in words :
            nums.append(sum(1 << (ord(x) - ord('a')) for x in set(word)))
        
        lenw = len(words)
        for i in xrange(lenw) :
            for j in xrange(lenw) :
                if not nums[i] & nums[j] :
                    ret = max(ret, len(words[i]) * len(words[j]))
        
        return ret
