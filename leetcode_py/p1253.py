from typing import List


class Solution:
    def reconstructMatrix(self, upper: int, lower: int, colsum: List[int]) -> List[List[int]]:

        # 贪心，先看全为2和全为 0的，其他就是分配1 和 0
        n = len(colsum)
        res = [[0] * n for _ in range(2)]
        for i,v in enumerate(colsum):
            if upper < 0 or lower < 0:
                return []
            if v == 2:
                res[0][i] = res[1][i] = 1
                upper -= 1
                lower -= 1
            elif v == 1:
                if upper >lower:
                    upper -= 1
                    res[0][i] = 1
                else:
                    lower -= 1
                    res[1][i] = 1
        return res if upper == 0 and lower == 0 else []
            
       


if __name__ == '__main__':

        # 剩下的就是1 和 0的
