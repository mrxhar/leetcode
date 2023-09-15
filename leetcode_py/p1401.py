from math import *


class Solution:
    def checkOverlap(self, radius: int, xCenter: int, yCenter: int, x1: int, y1: int, x2: int, y2: int) -> bool:
        # 我们只需要判断一个简单的东西即可，就是两个中心的连线以及连线上，矩阵的长度是多少，如果矩阵边缘的长度大于 中心距离 - r 代表重叠
        dist = 0
        if xCenter < x1 or xCenter > x2:
            dist += min((x1 - xCenter) ** 2, (x2 - xCenter) ** 2)
        if yCenter < y1 or yCenter > y2:
            dist += min((y1 - yCenter) ** 2, (y2 - yCenter) ** 2)
        return dist <= radius ** 2
