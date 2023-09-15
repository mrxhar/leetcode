class Solution:
    def largestInteger(self, num: int) -> int:
        # 奇偶 都进行排序
        # 最大值排序
        l = [int(d) for d in list(str(num))]
        n = len(l)

        for i in range(n - 1):
            for j in range(i + 1, n):
                if (l[i] - l[j]) % 2 == 0 and l[i] < l[j]:
                    l[i], l[j] = l[j], l[i]
        return int("".join(str(d) for d in l))
