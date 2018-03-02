class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        neg_flag = False
        if x < 0: 
            neg_flag = True
            x = abs(x)
        rev = 0
        while x != 0:
            rev = rev * 10 + x % 10
            x /= 10
        if rev >= (1 << 31) or rev < -(1 << 31):
            rev = 0
        if neg_flag:
            rev = -rev
        return rev
