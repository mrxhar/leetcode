
from typing import List


class Solution:
    def countStudents(self, students: List[int], sandwiches: List[int]) -> int:
        s1 = sum(students)
        s0 = len(students) - s1
        for i in range(len(sandwiches)):
            if (sandwiches[i] == 0 and  s0 > 0):
                s0-=1
            elif sandwiches[i] == 1 and  s1 > 0:
                s1 -=1
            else:
                break
        return s0 + s1