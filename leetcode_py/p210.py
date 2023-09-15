from typing import List
from collections import deque


class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        edges = [[] for _ in range(numCourses)]
        indeg = [0 for _ in range(numCourses)]

        for info in prerequisites:
            edges[info[1]].append(info[0])
            indeg[info[1]] += 1

        res = []
        q = []

        for i in range(numCourses):
            if indeg[i] == 0:
                q.append(i)
        
        while q:
            u = q.pop(0)
            res.append(u)
            for v in edges[u]:
                indeg[v]-=1
                if indeg[v] == 0:
                    q.append(v)
        return res if len(res) == numCourses else [] 