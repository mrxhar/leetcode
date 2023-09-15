# 每次拆分都是从两端开始
# 只需要两个相邻的值和大于m
from typing import List


class Solution:
    def canSplitArray(self, nums: List[int], m: int) -> bool:
        if len(nums ) <= 2:
            return True
        for i in range(1, len(nums)):
            if nums[i - 1] + nums[i] >= m:
                return True
        return False