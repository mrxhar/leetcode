from typing import List


class Solution:
    def numTimesAllBlue(self, flips: List[int]) -> int:
        # 前缀一致， i 前面的数都为 1
        maxnum = 0
        res = 0
        for i, num in enumerate(flips):

            maxnum = max(maxnum, num)
            if maxnum <= i + 1:
                # 这时候 我们 ＋ 1
                res = max(res, res + 1)

        return res
