from typing import List


class Solution:
    def eliminateMaximum(self, dist: List[int], speed: List[int]) -> int:
        n = len(dist)
        arrTime = [0] * n
        for i in range(n):
            arrTime[i] = (dist[i] - 1) // speed[i] + 1
        arrTime.sort()
        for i in range(n):
            if arrTime[i] < i:
                return i
        return n
