class Solution(object):
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        cand_len = len(candidates)
        
        def find_combination(nums, index):
            if sum(nums) == target:
                return [nums]
            if sum(nums) > target:
                return []

            rets = []
            for i in range(index, cand_len):
                new_nums = nums + [candidates[i]]
                rets.extend(find_combination(new_nums, i))
            return rets
        
        return find_combination([], 0)
