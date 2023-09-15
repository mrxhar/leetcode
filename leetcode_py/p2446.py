from typing import List


class Solution:
    def haveConflict(self, event1: List[str], event2: List[str]) -> bool:
        def gettime(time: str) -> int:
            return int(time[:2]) * 60 + int(time[3:])

        start1, end1 = gettime(event1[0]), gettime(event1[1])
        start2, end2 = gettime(event2[0]), gettime(event2[1])
        if start1 <= start2 and end1 >= end2:
            return True
        if start2 <= start1 and end2 >= end1:
            return True
    
        if start1 <= start2 and start2 <= end1 and end1 <= end2:
            return True
    
        if start2 <= start1 and start1 <= end2 and end2 <= end1:
            return True
        return False
   