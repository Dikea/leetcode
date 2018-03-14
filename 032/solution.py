class Solution(object):
    def longestValidParentheses(self, s):
        """
        :type s: str
        :rtype: int
        """
        
        s_len = len(s)
        max_len = 0
        stack = []
        start = -1
        for i in range(s_len):
            if s[i] == '(':
                stack.append(i)
            elif s[i] == ')':
                if stack:
                    stack.pop()
                    if stack:
                        max_len = max(max_len, i - stack[-1])
                    else:
                        max_len = max(max_len, i - start)
                else:
                    start = i
        return max_len
