class Solution:
    def waysToBuyPensPencils(self, total: int, cost1: int, cost2: int) -> int:
        if cost1 < cost2:
            return self.waysToBuyPensPencils(total, cost2, cost1)
        res = cnt = 0
        while total >= cost1 * cnt:
            res += (total - cost1 * cnt) // cost2 + 1
            cnt += 1
        return res
