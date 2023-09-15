from typing import List
import random


class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        # 快速选择
        def quick_select(nums,k):
            pivot = random.choice(nums)
            big,eqaul,small = [],[],[]
            for num in nums:
                if num > pivot:
                    big.append(num)
                elif num == pivot:
                    eqaul.append(num)
                else:
                    small.append(num)
            if k <= len(big):
                return quick_select(big,k)
            if len(nums) - len(small) < k:
                return quick_select(small,k - len(nums) + len(small)) # 找small 里面的数字
            return pivot
        return quick_select(nums,k)
