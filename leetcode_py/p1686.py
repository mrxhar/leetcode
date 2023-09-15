from typing import List


class Solution:
    def stoneGameVI(self, aliceValues: List[int], bobValues: List[int]) -> int:
        # 记录两个值和并且降序
        totalValue = [(a + b) for a, b in zip(aliceValues, bobValues)]
        totalValue.sort(reverse=True)
        ans = sum(totalValue[::2]) - sum(bobValues)
        if ans > 0:
            return 1
        elif ans == 0:
            return 0
        else:
            return -1
