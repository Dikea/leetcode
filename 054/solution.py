class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        m = len(matrix)
        if m == 0: 
            return []
        n = len(matrix[0])
        path = []
        up, down, left, right = 0, m - 1, 0, n - 1
        while up < down and left < right:
            path.extend([matrix[up][i] for i in range(left, right, 1)])
            path.extend([matrix[i][right] for i in range(up, down, 1)])
            path.extend([matrix[down][i] for i in range(right, left, -1)])
            path.extend([matrix[i][left] for i in range(down, up, -1)])
            up, down, left, right = up + 1, down - 1, left + 1, right - 1
        if left == right:
            path.extend([matrix[i][left] for i in range(up, down + 1)])
        elif up == down:
            path.extend([matrix[up][i] for i in range(left, right + 1)])
        return path
