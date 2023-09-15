from typing import List
from collections import heapq

# class Solution:
#     def kthSmallest(self, mat: List[List[int]], k: int) -> int:
#         a = mat[0][:k]  # k '
#         for row in mat[1:]: # 遍历后面的行
#             a = sorted(x + y for x in a for y in row)[:k] # 每次都只取前面k个
#         return a[-1]


# class Solution:
#     def kthSmallest(self, mat: List[List[int]], k: int) -> int:
#         def check(s):
#             left_k = k

#             def dfs(i, s):  # s 是剩余的个数
#                 if i < 0:
#                     nonlocal left_k
#                     left_k -= 1
#                     return left_k == 0
#                 for x in mat[i]:
#                     if x - mat[i][0] > s:
#                         break
#                     if dfs(i - 1, s - (x - mat[i][0])):
#                         # 选择 mat[i] 中的每个数的值的结果
#                         return True
#                 return False
#             return dfs(len(mat) - 1, s - sl)
#         sl = sum(row[0] for row in mat)
#         sr = sum(row[-1] for row in mat)
#         return sl + bisect_left(range(sl, sr), True, key=check)

class Solution:

    def kSmallesPairs(self, num1, num2, k):
        ans = []
        # num1 是 下一行， num2 是之前行的最小值的组合的和
        # 都是递增的，我们管理下一行的答案
        h = [(num1[0] + num2[0], 0, 0)]  # 小根堆 # 插入小根堆，第一个为和，第二第三为在两个数组的和
        while h and len(ans) < k:
            _, i, j = heappop(h)  # 最小的数
            # 只有堆中最小的数才能进行添加入 答案 ans
            ans.append(num1[i] + num2[j])  # 加入该数
            if j == 0 and i + 1 < len(num1):
                # 继续往堆里面加数，这时候的堆中可以添加两个数，一个是 目前还是第一个 j
                # 当最小值 还是 第一个数的时候，我们这时候需要往num1继续取值
                heappush(h, (num1[i + 1] + num2[0], i + 1, 0))
            if j + 1 < len(num2):
                # 如果不是的话，我们往 j + 1 取值，往答案下一个取值，放入堆，堆中元素进行管理
                heappush(h, (num1[i] + num2[j + 1], i, j + 1))
        return ans

    def kthSmallest(self, mat: List[List[int]], k: int) -> int:
        a = mat[0][:k]
        for row in mat[1:]:
            a = self.kSmallesPairs(row, a, k)

        return a[-1]
