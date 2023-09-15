from types import List


class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        count = 0
        prev = -1
        m = len(flowerbed)
        for i in range(m):
            if flowerbed[i] == 1:
                if prev == -1:
                    count += i // 2
                else:
                    count += (i - prev - 2) // 2 # 
                if count >= n:
                    return True

                prev = i

        if prev == -1:
            count += (m - 1) // 2
        else:
            count += (m - prev - 2) // 2 
        return count >= n
