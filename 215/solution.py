class Solution(object):
    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
      
        
        def findk(nums, left, right, k):
            pos = partition(nums, left, right)
            t = right - pos + 1
            if t > k:
                return findk(nums, pos + 1, right, k)
            elif t < k:
                return findk(nums, left, pos - 1, k - t)
            else:
                return nums[pos]
        
        def partition(nums, left, right):
            key = nums[left]
            low, high = left, right
            while low < high:
                while low < high and nums[high] >= key:
                    high -= 1
                nums[low] = nums[high]
                while low < high and nums[low] <= key:
                    low += 1
                nums[high] = nums[low]
            nums[low] = key
            return low
        
        return findk(nums, 0, len(nums) - 1, k)
