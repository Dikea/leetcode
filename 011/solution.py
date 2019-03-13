class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        length = len(height)
        max_area = 0
        l, r = 0, length - 1
        
        while l < r:
            area = min(height[l], height[r]) * (r - l)
            max_area = max(max_area, area)
            if height[l] > height[r]:
                r -= 1
            else:
                l += 1
            
        return max_area
