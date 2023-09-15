from typing import List


# class Solution:
#     def checkIfPrerequisite(self, numCourses: int, prerequisites: List[List[int]], queries: List[List[int]]) -> List[bool]:
#         # 遍历
#         f = [[False] * numCourses for _ in range(numCourses)]
#         for a,b in prerequisites:
#             f[a][b] = True
#         for k in range(numCourses):
#             for i in range(numCourses):
#                 for j in range(numCourses):
#                     if f[i][k] and f[k][j]:
#                         f[i][j] = True

#         return [f[a][b] for a,b in queries]

from collections import deque


class Solution:
    def checkIfPrerequisite(self, numCourses: int, prerequisites: List[List[int]], queries: List[List[int]]) -> List[bool]:
        f = [[False] * numCourses for _ in range(numCourses)]
        g = [[] for _ in range(numCourses)]
        indeg = [0 for _ in range(numCourses)]

        for a, b in prerequisites:
            g[a].append(b)
            indeg[b] += 1

        q = deque(i for i, x in enumerate(indeg) if x == 0)

        while q:
            i = q.popleft()
            for j in g[i]:
                f[i][j] = True
                for k in range(numCourses):
                    f[k][j] = f[k][j] or f[k][i]
                indeg[j] -= 1
                if indeg[j] == 0:
                    q.append(j)

        return [f[a][b] for a, b in queries]
