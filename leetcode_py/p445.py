# Definition for singly-linked list.
from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:

    def reverseList(self, head: Optional[ListNode]):
        pre = None
        cur = head
        while cur:
            next = cur.next
            cur.next = pre
            pre = cur
            cur = next
        return pre

    def addTwo(self, l1, l2):
        cur = dumpy = ListNode(0)
        carry = 0
        while l1 or l2 or carry:
            if l1:
                carry += l1.val
            if l2:
                carry += l2.val
            cur.next = ListNode(carry % 10)
            carry //= 10
            cur = cur.next
            if l1:
                l1 = l1.next
            if l2:
                l2 = l2.next
        return dumpy.next

    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        # 补齐，递归
        l1 = self.reverseList(l1)
        l2 = self.reverseList(l2)
        res = self.addTwo(l1, l2)
        return self.reverseList(res)
