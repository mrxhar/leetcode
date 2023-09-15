from typing import List


class Solution:
    def checkValidGrid(self, grid: List[List[int]]) -> bool:
        if grid[0][0]:
            return False

        n = len(grid)
        index = [[] for _ in range(n * n)]
        for i in range(n):
            for j in range(n):
                index[grid[i][j]] = [i, j]
        for i in range(1, n * n):
            x = abs(index[i][0] - index[i - 1][0])
            y = abs(index[i][1] - index[i - 1][1])
            if x * y != 2:
                return False
        return True
