from typing import List


class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        if len(nums) < 2:
            return False

        s = sum(nums)
        maxnum = max(nums)
        if s % 2 != 0 or maxnum > s // 2:
            return False

        dp = [False] * (s // 2 + 1)

        dp[0] = True
        for i in range(1, len(nums)):
            for j in range(len(dp) - 1, nums[i], -1):
                dp[j] = dp[j] or dp[j - nums[i]]

        return dp[-1]
