from typing import List
from collections import deque


class Solution:
    def minimumJumps(self, forbidden: List[int], a: int, b: int, x: int) -> int:
        # queue
        q, visited = deque([[0, 1, 0]]), set([0])
        lower, upper = 0, max(max(forbidden) + a, x) + b
        forbiddenSet = set(forbidden)
        while (q):
            position, direction, step = q.popleft()
            if position == x:
                return step
            nextPosition = position + a
            nextdirection = 1
            if (lower <= nextPosition <= upper and nextPosition not in visited and nextPosition not in forbiddenSet):
                q.append([nextPosition, nextdirection, step + 1])
                visited.add(nextdirection * nextPosition)
            if direction == 1:
                nextPosition = position - b
                nextdirection = -1
                if (lower <= nextPosition <= upper and nextPosition not in visited and nextPosition not in forbiddenSet):
                    q.append([nextPosition, nextdirection, step + 1])
                    visited.add(nextdirection * nextPosition)
        return -1
