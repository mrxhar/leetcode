# Definition for singly-linked list.
from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if(head==None or head.next==None):
            return head
        
        # 交换
        node1 = head
        node2 = head.next
        node3 = node2.next

        node1.next = self.swapPairs(node3)
        node2.next = node1
        return node2
        
