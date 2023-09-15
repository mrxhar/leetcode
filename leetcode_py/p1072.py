from typing import Counter, List


class Solution:
    def maxEqualRowsAfterFlips(self, matrix: List[List[int]]) -> int:
        cnt = Counter()
        for row in matrix:
            if row[0]:  # 翻转第一个为 1 的 行, 保证所有都为0
                for j in range(len(row)):
                    row[j] ^= 1
            cnt[tuple(row)] += 1
        return max(cnt.values())
