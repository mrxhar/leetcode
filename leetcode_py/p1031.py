from typing import List
from itertools import *

# class Solution:
#     def maxSumTwoNoOverlap(self, nums: List[int], firstLen: int, secondLen: int) -> int:
#         #  双指针
#         # 重叠判断
#         # i - j   j 比 i 大的时候 就应该 直接 遍历
#         # 预出列
#         n = len(nums)
#         preSum = [0] * (n + 1)
#         for i in range(1, n + 1):
#             preSum[i] = preSum[i - 1] + nums[i - 1]
#         print(preSum)
#         # 处理值
#         res = 0
#         for i in range(firstLen, n + 1):
#             for j in range(secondLen, n + 1):
#                 if secondLen <= j - i or firstLen <= i - j:
#                     print(i, j, res)
#                     res = max(res, preSum[i] - preSum[i -
#                                                       firstLen] + preSum[j] - preSum[j - secondLen])

#         return res


class Solution:
    def maxSumTwoNoOverlap(self, nums: List[int], firstLen: int, secondLen: int) -> int:
        s = list(accumulate(nums, initial=0))
        ans = 0
        maxSumA = maxSumB = 0

        for i in range(firstLen + secondLen, len(s)):
            # 维护最大的 左边的 a
            maxSumA = max(maxSumA, s[i - secondLen] -
                          s[i - secondLen - firstLen])
            maxSumB = max(maxSumB, s[i - firstLen] -
                          s[i - secondLen - firstLen])
            # 更新 目前的 a + b
            ans = max(ans, maxSumA + s[i] - s[i - secondLen],
                      maxSumB + s[i] - s[i - firstLen])

        return ans
