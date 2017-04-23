class Solution(object):
    def longestLine(self, M):
        """
        :type M: List[List[int]]
        :rtype: int
        """
        if not M: return 0
        m, n = len(M), len(M[0])
        ans = 0
        for i in range(m):
            length = 0
            for j in range(0, n):
                if M[i][j] == 1:
                    length += 1
                else:
                    length = 0
                ans = max(ans, length)
        
        for i in range(n):
            length = 0
            for j in range(0, m):
                if M[j][i] == 1:
                    length += 1
                else:
                    length = 0
                ans = max(ans, length)
                    
        steps = [[0, 0]]
        for i in range(1, m): steps.append([i, 0])
        for i in range(1, n): steps.append([0, i])
        
        for step in steps:
            x = step[0]
            y = step[1]
            length = 0
            while x < m and y < n:
                if M[x][y] == 1:
                    length += 1
                else:
                    length = 0
                ans = max(ans, length)
                # print 'length', x, y, length
                x += 1
                y += 1
        steps = [[0, n-1]]
        for i in range(1, m): steps.append([i, n-1])
        for i in range(0, n-1): steps.append([0, i])
        for step in steps:
            x = step[0]
            y = step[1]
            length = 0
            while x < m and 0 <= y < n:
                if M[x][y] == 1:
                    length += 1
                else:
                    length = 0
                ans = max(ans, length)
                # print 'length', x, y, length
                x += 1
                y -= 1
                
        return ans
        
