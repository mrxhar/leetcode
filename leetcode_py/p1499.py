from typing import List
from collections import deque


class Solution:
    def findMaxValueOfEquation(self, points: List[List[int]], k: int) -> int:

        # 遍历，这么说? ,遍历得最大长度为 k
        # 滑动窗口
        # res = -inf
        # for i in range(len(points)):
        #     # 最长为多少，最后一个点的 x 坐标，当然我们也可以不适用x坐标而是用点来确定

        #     # 滑动窗口
        #     j = 1
        #     while i + j < len(points) and points[i + j][0] < points[i][0] + k:
        #         # 滑动窗口
        #         res = max(res, points[i][1] + points[i + j][1]
        #                   + points[i + j][0] - points[i][0])
        #         j += 1
        # return res

        # res = -inf

        # heap = [] # 堆中放了什么？？？  放了 x - y 的值，这是一个小根堆，每次我们都弹出不符合条件的小根堆，没啥用，我们需要找到最大的 -x + y ,也就是最小的符合条件的 y-x

        # for x,y in points:
        #     while heap and x - heap[0][1] > k:
        #         heapq.heappop(heap) # 弹出堆顶元素
        #         # 弹出不符合条件的值
        #     if heap:
        #         res = max(res, x + y -  heap[0][0])
        #     heapq.heappush(heap, (x - y, x))
        # return res

        ans = -float("inf")
        q = deque()
        for x, y in points:
            while q and q[0][0] < x - k:  # 符合条件
                q.popleft()
            if q:
                ans = max(ans, x + y + q[0][1])
            while q and q[-1][1] <= y - x:  # 不如新来的
                q.pop()
            q.append((x, y - x))
        return ans
