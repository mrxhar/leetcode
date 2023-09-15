class Solution:
    def minBitFlips(self, start: int, goal: int) -> int:
        res = 0
        tmp = start ^ goal
        while tmp:
            res += tmp & 1
            tmp >>= 1
        return res