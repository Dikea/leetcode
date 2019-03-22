class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums.sort()
        n = len(nums)
        results = [] 
        
        for i in range(n):
            if nums[i] > 0: 
                break
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            l, r = i + 1, n - 1
            key = -nums[i]
            while l < r:
                if nums[l] + nums[r] < key:
                    l += 1
                elif nums[l] + nums[r] > key:
                    r -= 1
                else:
                    results.append([nums[i], nums[l], nums[r]])
                    while l < r and nums[l + 1] == nums[l]:
                        l += 1
                    while l < r and nums[r - 1] == nums[r]:
                        r -= 1
                    l += 1
		    r -= 1
                    
        return results
