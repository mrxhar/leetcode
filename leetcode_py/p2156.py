from collections import deque
from typing import List


class Solution:

    def highestRankedKItems(self, grid: List[List[int]], pricing: List[int], start: List[int], k: int) -> List[List[int]]:
        items = []
        q = deque([(start[0], start[1], 0)])
        if (pricing[0] <= grid[start[0]][start[1]] <= pricing[1]):
            items.append([0, grid[start[0]][start[1]], start[0], start[1]])
        grid[start[0]][start[1]] = 0
        m = len(grid)
        n = len(grid[0])
        dx = [-1, 0, 1, 0]
        dy = [0, -1, 0, 1]
        while q:
            x, y, d = q.popleft()
            for i in range(4):
                nx = x + dx[i]
                ny = y + dy[i]
                if 0 <= nx < m and 0 <= ny < n and grid[nx][ny] > 0:
                    q.append((nx, ny, d + 1))
                    if pricing[0] <= grid[nx][ny] <= pricing[1]:
                        items.append([d + 1, grid[nx][ny], nx, ny])
                    grid[nx][ny] = 0  # 标记
        items.sort()
        res = [item[2:] for item in items]
        return res[:k]
