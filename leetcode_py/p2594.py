from typing import Counter, List
from math import isqrt, sqrt


class Solution:


    def repairCars(self, ranks: List[int], cars: int) -> int:
        cnt =  Counter(ranks)
        left =0
        right = min(cnt) * cars * cars
        while left + 1 < right:
            mid = (left + right) // 2
            if sum(isqrt(mid // r) * c  for r,c in cnt.items()) >= cars:
                right = mid
            else:
                left = mid
        return right
  
        