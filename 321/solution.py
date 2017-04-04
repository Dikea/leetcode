class Solution(object):
    def maxNumber(self, nums1, nums2, k):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :type k: int
        :rtype: List[int]
        """
        def getMax(nums, t):
            ans = []
            index = 0
            size = len(nums)
            for i in xrange(size) :
                while ans and len(ans) + size - i > t and nums[i] > ans[-1] :
                    ans.pop()
                if len(ans) < t :
                    ans.append(nums[i])
            return ans
                
        
        def merge(nums1, nums2):
            ans = []
            while nums1 or nums2 :
                if nums1 > nums2 :
                    ans.append(nums1[0])
                    nums1 = nums1[1:]
                else :
                    ans.append(nums2[0])
                    nums2 = nums2[1:]
            return ans
                    
    
        ret = []
        len1, len2 = len(nums1), len(nums2)
        for i in xrange(max(0, k - len2), min(k, len1) + 1) :
            tmp = merge(getMax(nums1, i), getMax(nums2, k - i))
            ret = max(ret, tmp)
        
        return ret
