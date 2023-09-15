# Definition for a binary tree node.
from typing import Optional


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Codec:

    def serialize(self, root: Optional[TreeNode]) -> str:
        """Encodes a tree to a single string.
        """
        arr = []
        # 前序遍历

        def dfs(root):
            if not root:
                return
            dfs(root.left)
            dfs(root.right)
            arr.append(root.val)

        dfs(root)
        return ' '.join(map(str, arr))

    def deserialize(self, data: str) -> Optional[TreeNode]:
        """Decodes your encoded data to tree.
        """
        arr = list(map(int, data.split()))

        def construct(lower, upper):
            if arr == [] or arr[-1] < lower or arr[-1] > upper:
                return None
            val = arr.pop()
            root = TreeNode(val)
            root.right = construct(val, upper)
            root.left = construct(lower, val)
            return root
        return construct(-inf, inf)
