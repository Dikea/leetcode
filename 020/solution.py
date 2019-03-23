class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        stack = []
        p_dict = {")": "(", "]": "[", "}": "{"}
        
        for ch in s:
            if stack and ch in p_dict and stack[-1] == p_dict[ch]:
                stack.pop()
            else:
                stack.append(ch)
                
        return True if not stack else False
