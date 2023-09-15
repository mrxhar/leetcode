class Solution:
    def numberOfCuts(self, n: int) -> int:
        if n <= 1:
            return 0
        if not n % 2:
            return n // 2
        return n
