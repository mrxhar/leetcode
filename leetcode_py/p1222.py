from typing import List


class Solution:
    def queensAttacktheKing(self, queens: List[List[int]], king: List[int]) -> List[List[int]]:
        # 遍历八个方向

        res = []
        for dx in [-1, 0, 1]:
            for dy in [-1, 0, 1]:
                if dx == 0 and dy == 0:
                    continue
                kx, ky = king
                while 0 <= kx < 8 and 0 <= ky < 8:
                    if [kx, ky] in queens:
                        res.append([kx, ky])
                        break
                    kx += dx
                    ky += dy
        return res
