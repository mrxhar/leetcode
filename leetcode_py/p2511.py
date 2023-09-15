from typing import List


class Solution:
    def captureForts(self, forts: List[int]) -> int:
        ans = pre = 0
        for i in range(len(forts)):
            if forts [i] == -1 or forts[i] == 1:
                if forts[i] != forts[pre]:
                    ans = max(ans, i- pre - 1)
                pre = i
        return ans