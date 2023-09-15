from typing import List


class Solution:
    def maxAlternatingSum(self, nums: List[int]) -> int:
        f = g = 0
        for num in nums:
            f,g= max(f,g + num),max(g, f-num)
        return max(f,g)

