class Solution(object):
    def jump(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        step = 0
        lastReach = 0
        reach = 0
        for i in range(len(nums)):
            if lastReach < i :
                step += 1
                lastReach = reach;
            reach = max(reach, nums[i] + i)
        return step
        
