class Solution(object):
	def updateMatrix(self, matrix):
		h, w = len(matrix), len(matrix[0])
		ans = [[0] * w for x in range(h)]
		queue = [(x, y) for x in range(h) for y in range(w) if matrix[x][y]]
		step = 0
		while queue:
			step += 1
			nqueue, mqueue = [], []
			for x, y in queue:
				zero = False
				for dx, dy in zip((1, 0, -1, 0), (0, 1, 0, -1)):
					nx, ny = x + dx, y + dy
					if 0 <= nx < h and 0 <= ny < w and matrix[nx][ny] == 0:
						zero = True
						break
				if zero:
					ans[x][y] = step
					mqueue.append((x, y))
				else:
					nqueue.append((x, y))
			for x, y in mqueue:
				matrix[x][y] = 0
			queue = nqueue
		return ans
