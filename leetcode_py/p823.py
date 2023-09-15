from typing import List

class Solution:
    def numFactoredBinaryTrees(self, arr: List[int]) -> int:
        # 动态规划
        res = 0
        mod = 10**9 + 7
        n = len(arr)
        arr.sort()
        dp = [1 for _ in range(n)]
        vis = {}
        for i in range(n):
            j = 0
            while arr[j] * arr[j] <= arr[i]:
                # 这样可以将 j 确保为比较小的那个值
                if arr[i] % arr[j] == 0 and ((arr[i] // arr[j]) in vis):
                    # 这样的到 k 了
                    k = vis[arr[i] // arr[j]]
                    if j == k:
                        dp[i] = (dp[i] + dp[j] * dp[k]) % mod
                    else:
                        dp[i] = (dp[i] + dp[j] * dp[k] * 2) % mod
                j += 1
            vis[arr[i]] = i
            res = (res + dp[i]) % mod
        return res
