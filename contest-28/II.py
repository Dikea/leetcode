class Solution(object):
    def optimalDivision(self, nums):
        """
        :type nums: List[int]
        :rtype: str
        """
        ret = ''
        size = len(nums)
        if size == 0: return ret
        if size == 1: 
            ret += str(nums[0])
            return ret
        if size == 2:
            ret += str(nums[0]) + '/' + str(nums[1])
            return ret
        for i in range(size):
            ret += str(nums[i])
            if i != size - 1 : ret += '/'
            if i == 0 : ret += '('
            if i == size - 1 : ret += ')'
        return ret
