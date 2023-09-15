from typing import List


class Solution:
    def maximumEvenSplit(self, finalSum: int) -> List[int]:
        # 贪心算法
        if finalSum % 2:
            return []
        i = 2
        res = []
        while finalSum:
            if finalSum >= 2 * i:
                res.append(i)
                finalSum -= i
            else:
                res.append(finalSum)
                finalSum = 0
            i += 2
        return res
