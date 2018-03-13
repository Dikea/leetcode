from collections import Counter

class Solution(object):
    def minWindow(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        ret = ""
        need = Counter(t)
        s_len, t_len = len(s), len(t)   
        left = 0
        min_len = s_len + 1
        count = 0
        for right in range(s_len):
            ch = s[right]
            if ch in need:
                need[ch] -= 1
                if need[ch] >= 0: 
                    count += 1
            while count == t_len:
                if right - left + 1 < min_len:
                    min_len = right - left + 1
                    ret = s[left:right+1]
                ch = s[left]
                if ch in need:
                    need[ch] += 1
                    if need[ch] > 0:
                        count -= 1
                left += 1
        return ret
