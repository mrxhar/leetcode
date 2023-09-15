from typing import List


class Solution:
    def minNumber(self, nums1: List[int], nums2: List[int]) -> int:
        def same() -> int:
            s = set(nums1) & set(nums2)
            return -1 if not s else min(s)
    
        if (x:=same()) != -1:
            return x
    
        x = min(nums1)
        y = min(nums2)
        return min(x,y) * 10 + max(x,y)

    