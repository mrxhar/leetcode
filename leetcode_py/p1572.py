from typing import List


class Solution:
    def diagonalSum(self, mat: List[List[int]]) -> int:
        res = 0
        n = len(mat)
        for i in range(n):
            res += (mat[i][i] + mat[i][n - 1 - i])
        return res - (n % 2 and mat[n // 2][n // 2])
