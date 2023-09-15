from typing import List


class Solution:
    def sampleStats(self, count: List[int]) -> List[float]:
        minimum = 255
        maximum = 0
        median = 0

        mode = 0
        mode_count = 0

        sum = 0 
        n = 0
        for k, c in enumerate(count):
            if c != 0:
                sum += k * c
                if c > mode_count:
                    mode_count = c
                    mode = k
                minimum = min(minimum,k)
                maximum = max(maximum,k)
                n += c

        mean = sum/n
        sum_c= 0
        left = -1
        print(n)
        for k,c in enumerate(count):
            if c:
                sum_c += c
                if sum_c * 2 == n:
                    left = k
                    print(left)
                elif sum_c * 2 > n:
                    if left == -1 :
                        median = k  
                    else:
                        median = (left + k) / 2
                    break
        return [minimum,maximum,mean,median,mode]
                