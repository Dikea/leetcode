class Solution(object):
    def removeBoxes(self, boxes):
        """
        :type boxes: List[int]
        :rtype: int
        """
        self.color, self.length = [], []
        for box in boxes:
            if self.color and self.color[-1] == box:
                self.length[-1] += 1
            else:
                self.color.append(box)
                self.length.append(1)
        m, n = len(self.color), len(boxes)
        self.dp = [[[0] * n for x in range(m)] for y in range(m)]
        return self.solve(0, m - 1, 0)
        
    def solve(self, l, r, k):
        if l > r: return 0
        if self.dp[l][r][k]: return self.dp[l][r][k]
        points = self.solve(l, r- 1, 0) + (self.length[r] + k) ** 2
        for i in range(l, r):
            if self.color[i] == self.color[r]:
                points = max(points, self.solve(l, i, self.length[r] + k) + self.solve(i + 1, r - 1, 0))
        self.dp[l][r][k] = points
        return points;
