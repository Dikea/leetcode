class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        length = len(s)
        if length == 0:
            return 0
        begin = 0
        max_len = 1
        for i in range(1, length):
            for j in range(begin, i):
                if s[j] == s[i]:
                    begin = j + 1
            max_len = max(max_len, i - begin + 1)
        return max_len


class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        length = len(s)
        if length == 0:
            return 0
        begin = 0
        max_len = 0
        index_dict = {}
        for i in range(0, length):
            char = s[i]
            if char in index_dict:
                begin = max(begin, index_dict[char] + 1)
            max_len = max(max_len, i - begin + 1)
            index_dict[char] = i
        return max_len
