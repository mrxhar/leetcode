import collections
from heapq import heappop, heappush


class DinnerPlates:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.stacks = []
        self.h = []  # 小根堆

    def push(self, val: int) -> None:
        if self.h and self.h[0] >= len(self.stacks):  # 最小索引都大于stacks长度，超出索引
            self.h = []
        if self.h:
            self.stacks[self.h[0]].append(val)
            if len(self.stacks[self.h[0]]) == self.capacity:
                heappop(self.h)  # 弹出最小索引
        else:
            # 没有未满的栈
            self.stacks.append([val])
            if self.capacity > 1:
                heappush(self.h, len(self.stacks)-1)

    def pop(self) -> int:
        return self.popAtStack(len(self.stacks)-1)

    def popAtStack(self, index: int) -> int:
        if index >= len(self.stacks) or index < 0 or len(self.stacks[index]) == 0:
            # 索引超出范围或者索引所在的栈为空
            return -1

        if len(self.stacks[index]) == self.capacity:
            heappush(self.h, index)
        val = self.stacks[index].pop()
        while self.stacks and len(self.stacks[-1]) == 0:
            self.stacks.pop()
        return val
