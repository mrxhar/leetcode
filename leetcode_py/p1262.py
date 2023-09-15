from typing import List


class Solution:
    def maxSumDivThree(self, nums: List[int]) -> int:
        # # 贪心，先选取 num 的和 最后的最大数值为 sum - n*3 = diff
        # # diff + 3 * i
        # # 则我们需要选取的值为 sum - 3 *(n - i) 这时候是我们需要剔除的值，只要剔除的值最小，我们选取的值就最大
        # # 反过来贪心，我们记录数值的类型，只有余 1 和 余 2 的值不能构成 3 的倍数，只要 余 2 和 余 1 的数可以添加构成 3 的倍数即可
        # # 可以是一个 deque ，这样内存大小会非常校
        # a = [x for x in nums if x % 3 == 0]
        # b = sorted([x for x in nums if x % 3 == 1], reverse=True)
        # c = sorted([x for x in nums if x % 3 == 2], reverse=True)

        # ans = 0
        # lb, lc = len(b), len(c)
        # for cntb in [lb - 2, lb - 1, lb]:
        #     if cntb >= 0:
        #         for cntc in [lc - 2, lc - 1, lc]:
        #             if cntc >= 0 and (cntb - cntc) % 3 == 0:
        #                 ans = max(ans, sum(b[:cntb]) + sum(c[:cntc]))
        # return ans + sum(a)
        # 还有一种方法，动态规划，选与不选的问题
        f = [[-inf] * 3 for _ in range(2)]

        f[0][0] = 0
        for i, x in enumerate(nums):
            for j in range(3):
                f[(i + 1) % 2][j] = max(f[i % 2][0], f[i % 2][(j + x) % 3] + x)
        return f[-1][0]
