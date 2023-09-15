from typing import List
from collections import heapq


class Solution:
    def scheduleCourse(self, courses: List[List[int]]) -> int:
        courses.sort(key=lambda c: c[1])
        # 按照 结束时间进行排序

        q = list()

        total = 0
        for ti, di in courses:
            if total + ti <= di:
                # 这时候可以加进去
                heapq.heappush(q, -ti)  # 使用负数构建大根堆
            elif q and -q[0] > ti:  # 大根堆，最大的元素大于 ti
                # 这时候将大根堆，堆顶拿出来，因为有更优的方案
                total -= -q[0] - ti
                heapq.heappop(q)
                heapq.heappush(q, -ti)
        return len(q)
