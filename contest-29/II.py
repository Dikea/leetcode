class Solution(object):
    def arrayPairSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.sort()
        size = len(nums)
        ans = 0
        for i in range(0, size, 2):
            ans += nums[i]
            
        return ans
