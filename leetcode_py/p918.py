from typing import List


class Solution:
    def maxSubarraySumCircular(self, nums: List[int]) -> int:
        # 直接使用 最大最小
        n = len(nums)
        maxSum = nums[0]
        minSum = nums[0]
        curMax = curMin = 0
        total = 0
        for num in nums:
            total += num
            curMax = max(0,curMax) + num
            curMin = min(0,curMin) + num

            maxSum = max(maxSum ,curMax)
            minSum = min(minSum,curMin)
        return maxSum if maxSum > 0 else total - minSum
            