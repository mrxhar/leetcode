from typing import List


# class Solution:
#     def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:

#         # 广度优先遍历
#         # 图和入度表
#         graph = [[] for _ in range(numCourses)]
#         in_degree = [0 for _ in range(numCourses)]
#         for i, j in prerequisites:
#             graph[i].append(j)
#             in_degree[j] += 1

#         # 表建立完成
#         # 入度为0的节点入队
#         queue = []
#         for i in range(numCourses):
#             if in_degree[i] == 0:
#                 queue.append(i)

#         # 开始遍历
#         while queue:
#             course = queue.pop(0)
#             for i in graph[course]:
#                 in_degree[i] -= 1
#                 if in_degree[i] == 0:
#                     queue.append(i)

#         # 遍历结束，如果所有节点都被遍历，则返回True
#         return all(in_degree[i] == 0 for i in range(numCourses))

class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        # 深度优先遍历
        # 图和邻接表
        graph = [[] for _ in range(numCourses)]
        visited = [0 for _ in range(numCourses)]
        for i, j in prerequisites:
            graph[i].append(j)

        # 表建立完成
        # 邻接表建立完成
        # 遍历所有节点，如果节点没有被访问过，则递归访问其邻接表

        # 开始遍历
        def dfs(i):
            if visited[i] == -1:  # 访问锅，闭环了
                return False
            if visited[i] == 1:  # 访问得是已经修好
                return True
            visited[i] = -1
            for j in graph[i]:
                if not dfs(j):
                    return False
            visited[i] = 1
            return True

        for i in range(numCourses):
            if not dfs(i):
                return False
        return True
