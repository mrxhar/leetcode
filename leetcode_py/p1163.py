class Solution:
    def lastSubstring(self, s: str) -> str:
        i, j, n = 0, 1, len(s)
        while j < n:
            # 遍历
            k = 0
            while k + j < n and s[i+k] == s[j + k]:  # 到达不等的哪一个位置
                k += 1
            if k + j < n and ord(s[i + k]) < ord(s[j + k]):
                t = i
                i = j
                # 这条主要是缩短时间 如果 遍历长度过了 j 这代表 这时候中间的这部分全部相等，直接判断下一步 ，这一段肯定小于
                j = max(j + 1, t + k + 1)
            else:
                j = j + k + 1 # 这时候遍历的所有的都是小于
        return s[i:]
