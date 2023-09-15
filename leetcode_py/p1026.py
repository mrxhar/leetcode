# Definition for a binary tree node.
from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def maxAncestorDiff(self, root: Optional[TreeNode]) -> int:
        ans = 0

        def dfs(node):
            if node is None:
                return float("inf"), -float("inf")
            mn = mx = node.val

            l_mn, l_mx = dfs(node.left)
            r_mn, r_mx = dfs(node.right)
            mn = min(mn, l_mn, r_mn)
            mx = max(mx, l_mx, r_mx)
            nonlocal ans
            ans = max(ans, node.val-mn, mx-node.val)
            return mn, mx
        dfs(root)
        return ans
