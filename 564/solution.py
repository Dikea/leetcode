class Solution(object):
    def nearestPalindromic(self, n):
        """
        :type n: str
        :rtype: str
        """
        def getabs(x):
            return abs(int(n) - int(x))
        
        l = len(n)
        result = [str(10**x + d) for x in (l - 1, l) for d in (-1, 1)]
        
        prefix = n[:(l+1)/2]
        pre = int(prefix)
        for p in map(str, (pre - 1, pre, pre + 1)):
            result.append(p + (p[:-1] if l%2 else p[:])[::-1])
        
        for res in result:
            if res == n:
                result.remove(res)
        
        print result
        ans = None
        for res in result:
            if res == n: continue
            if ans is None or getabs(res) < getabs(ans) or (getabs(res) == getabs(ans) and int(res) < int(ans)):
                ans = res
                
        return ans
        
        
        

