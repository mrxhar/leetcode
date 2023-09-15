# Definition for singly-linked list.
from typing import List
from typing_extensions import Optional

import collections

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def nextLargerNodes(self, head: Optional[ListNode]) -> List[int]:
        q = []
        cur = head
        ans = []
        idx = -1
        while cur:
            idx +=1
            ans.append(0)
            while q and q[-1][0] < cur.val:
                ans[q[-1][1]] = cur.val
                q.pop()
            q.append([cur.val,idx])
            cur = cur.next
        return ans