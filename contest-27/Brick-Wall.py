class Solution(object):
    def leastBricks(self, wall):
        """
        :type wall: List[List[int]]
        :rtype: int
        """
        edgeMap = {}
        
        for row in wall :
            cnt = 0
            for i in range(len(row) - 1) :
                cnt += row[i]
                if cnt in edgeMap : edgeMap[cnt] += 1
                else : edgeMap[cnt] = 1
        # print edgeMap
        maxEdge = 0
        for edge in edgeMap :
           maxEdge = max(maxEdge, edgeMap[edge]) 
        
        return len(wall) - maxEdge
