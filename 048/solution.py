from copy import deepcopy

class Solution(object):
    def rotate(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        tempMatrix = deepcopy(matrix)
        m, n = len(matrix), len(matrix[0])
        for i in range(0, m):
            for j in range(0, n):
                matrix[j][m - 1 - i] = tempMatrix[i][j]
                print j, m - 1 - i, tempMatrix[i][j]
        
