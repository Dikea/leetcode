class Solution(object):
    def checkRecord(self, s):
        """
        :type s: str
        :rtype: bool
        """
        size = len(s)
        num_A, num_L = 0, 0
 
        for i in range(size):
            if s[i] == 'A': num_A += 1
            if s[i] == 'L': num_L += 1
            else: num_L = 0
            if num_A > 1 or num_L > 2: 
                return False
        return True
