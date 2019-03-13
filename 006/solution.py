class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        if len(s) == 1 or numRows == 1:
            return s
        
        res = [""] * numRows
        index = 0
        for idx, ch in enumerate(s):
            if index == 0:
                step = 1
            if index == numRows - 1:
                step = -1
            res[index] += ch
            index += step
        return "".join(res)
