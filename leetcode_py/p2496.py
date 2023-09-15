from typing import List


class Solution:
    def maximumValue(self, strs: List[str]) -> int:
        # def get_len(s: str) -> int:
        #     # 数字
        #     for s in str:
        #         if not s.isdigit():
        #             return len(s)
        #     return int(s)
        # max_len = 0

        # for str in strs:
        #     max_len = max(get_len(str),max_len)
        # return max_len
        res  =0
        for s in strs:
            is_digits = all(c.isdigit() for c in s)
            res = max(res,int(s) if is_digits else len(s))
        return res
            