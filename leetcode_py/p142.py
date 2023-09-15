# Definition for singly-linked list.
from typing import Optional


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        fast = last = head
        while True:
            if not fast or not fast.next:
                return None
            if fast == last:
                break
            fast = fast.next.next
            last = last.next
        fast = head
        while fast != last:
            fast = fast.next
            last = last.next
            
        return fast