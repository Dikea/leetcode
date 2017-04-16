class Solution(object):
    def splitLoopedString(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        loop = ''
        size = len(strs)
        for i in range(size):
            strs[i] = max(strs[i], strs[i][::-1])
            
        ans = ''
        
        for i in range(size):
            for j in range(len(strs[i])):
                newstr = str(strs[i][j:]) + ''.join(strs[i+1:]) + ''.join(strs[:i]) + str(strs[i][:j])
                ans = max(ans, newstr)
                tempStr = strs[i][::-1]
                newstr = str(tempStr[j:]) + ''.join(strs[i+1:]) + ''.join(strs[:i]) + str(tempStr[:j])
                ans = max(ans, newstr)

        return ans
            
 
