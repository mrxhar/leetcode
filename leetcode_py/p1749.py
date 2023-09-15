from typing import List


class Solution:
    def maxAbsoluteSum(self, nums: List[int]) -> int:
        s = mn = mx = 0
        for num in nums:
            s += num
            mn = min(s, mn)
            mx = max(s, mx)
        return mx - mn
