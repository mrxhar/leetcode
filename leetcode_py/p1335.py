from typing import List
from itertools import accumulate

# class Solution:
#     def minDifficulty(self, jobDifficulty: List[int], d: int) -> int:
#         # 递归
#         n = len(jobDifficulty)
#         if n < d:
#             return -1

#         @cache
#         def dfs(i, j):
#             # i 天数
#             # j 索引，剩余的任务索引
#             if i == 0:
#                 return max(jobDifficulty[:j + 1])
#             res, mx = inf, 0
#             for k in range(j, i - 1, -1):  # 可以遍历到 i-1 的为位置
#                 mx = max(mx, jobDifficulty[k])
#                 res = min(res, dfs(i - 1, k - 1) + mx)
#             return res
#         return dfs(d - 1, n - 1)


class Solution:
    # def minDifficulty(self, jobDifficulty: List[int], d: int) -> int:
    #     # 动态递归
    #     # 缩小问题规模
    #     n = len(jobDifficulty)
    #     if n < d:
    #         return -1
    #     f = list(accumulate(jobDifficulty, max))

    #     for i in range(1, d):
    #         for j in range(n - 1, i - 1, -1):
    #             f[j] = inf
    #             mx = 0
    #             for k in range(j, i - 1, -1):
    #                 mx = max(mx, jobDifficulty[k])
    #                 f[j] = min(f[j], f[k - 1] + mx)
    #     return f[-1]

    def minDifficulty(self, jobDifficulty: List[int], d: int) -> int:
        n = len(jobDifficulty)
        if n < d:
            return -1

        f = [[inf] * n for _ in range(d)]  # dp
        f[0] = list(accumulate(jobDifficulty, max))
        for i in range(1, d):
            st = []  # 单调栈 单调递减的栈
            for j in range(i, n):  # 遍历数组
                mn = f[i - 1][j - 1]  # 当前元素，我们需要求取 i-1，j-1 的最小值，先拿去之前的运算结果
                while st and jobDifficulty[st[-1][0]] <= jobDifficulty[j]:
                    # 栈中元素的最小值小于 当前工作
                    # 弹出，并且转移
                    mn = min(mn, st.pop()[1])  # 栈中元素，之前的计算更小的值
                f[i][j] = mn + jobDifficulty[j]  # 加上这个工作，栈中没有比当前工作更大的元素了
                if st:
                    # 栈中还有元素，我们继续比较，这时候栈里面的 代价最小值是大于当前工作的，我们求转移的值是否的大小
                    f[i][j] = min(f[i][j], f[i][st[-1][0]])
                st.append((j, mn))  # 压入栈的是 j 以及在最小值，这个最小值 是 i-1的
                # 可以看出每次到下一天的时候栈都会清空，这样便于维护
        return f[-1][-1]
