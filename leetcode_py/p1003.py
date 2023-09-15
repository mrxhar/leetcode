class Solution:
    def isValid(self, s: str) -> bool:
        # 可以采用丢弃的方法，丢掉后面和前面的，然后依次丢,迭代的丢
        stk = []

        for c in s:
            stk.append(c)
            if ''.join(stk[-3:]) == "abc":
                stk[-3:] = []
        return len(stk) == 0
