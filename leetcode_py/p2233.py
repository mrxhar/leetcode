from typing import List
import heapq


class Solution:
    def maximumProduct(self, nums: List[int], k: int) -> int:
        # # 最下堆
        # mod = 10** 9 + 7
        # heapq.heapify(nums)
        # while k :
        #     k -= 1
        #     num = heapq.heappop(nums)
        #     heapq.heappush(num + 1)
        # res = 1
        # for num in nums:
        #     res *= num
        #     res %= mod
        # return res

        # 数学方法
        mod = 10 ** 9 + 7
        nums.sort()
        n = len(nums)
        nums.append(float("inf"))
        for i in range(n):
            tmp = (i + 1) * (nums[i + 1] - nums[i])
            if k >= tmp:
                k -= tmp
                continue
            d = k // (i + 1)
            m = k % (i + 1)
            for j in range(i + 1):
                nums[j] = nums[i] + d
                if j < m:
                    nums[j] += 1
            break
        nums.pop()
        res = 1
        for num in nums:
            res *= num
            res %= mod
        return res
