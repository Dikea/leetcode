class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        nums.sort()
        length = len(nums)
        closest_val = sum(nums[:3])
        
        for i in range(0, length - 2):
            l, r = i + 1, length - 1
            while l < r:
                val = nums[i] + nums[l] + nums[r]
                if abs(val - target) < abs(closest_val - target):
                    closest_val = val
                if val < target:
                    l += 1
                elif val > target:
                    r -= 1
                else:
                    break

        return closest_val
