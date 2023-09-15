from math import comb
from typing import List


class Solution:
    def kthSmallestPath(self, destination: List[int], k: int) -> str:
        v, h = destination

        if k == 1:
            return 'H' * h + 'V' * v

        cnt = 1
        for i in range(h - 1, 0, -1):
            pre = int(comb(v - 1 + h - i, h - i))
            cnt += pre
            if cnt > k:
                # 下一个是 V
                return 'H' * i + 'V' + self.kthSmallestPath([v - 1, h - i], k - cnt + pre)
            elif cnt == k:
                return 'H' * i + 'V' * v + 'H' * (h - i)  # 中间部分全为 V
        return 'V' + self.kthSmallestPath([v - 1, h], k - cnt)
