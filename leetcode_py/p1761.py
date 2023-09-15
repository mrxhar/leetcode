from typing import List
from numpy import inf


class Solution:
    def minTrioDegree(self, n: int, edges: List[List[int]]) -> int:
        g = defaultdict(set)
        degree = [0] * n

        h = defaultdict(list)

        for x, y in edges:
            x -= 1
            y -= 1
            g[x].add(y)
            g[y].add(x)
            degree[x] += 1
            degree[y] += 1

        for x, y in edges:
            x -= 1
            y -= 1
            if degree[x] < degree[y] or (degree[x] == degree[y] and x < y):
                h[x].append(y)
            else:
                h[y].append(x)
        ans = inf
        for i in range(n):
            for j in h[i]:
                for k in h[j]:
                    if k in g[i]:
                        ans = min(ans, degree[i] + degree[j] + degree[k] - 6)
        return -1 if ans == inf else ans
