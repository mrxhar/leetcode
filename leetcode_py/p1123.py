# Definition for a binary tree node.

from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def lcaDeepestLeaves(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        def dfs(root):
            if not root:
                return 0, None
            l, lc = dfs(root.left)
            r, rc = dfs(root.right)
            if l > r:
                return l+1, lc
            elif r > l:
                return r+1, rc
            return r+1, root

        return dfs(root)[1]
