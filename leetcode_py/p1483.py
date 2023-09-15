from typing import List


class TreeAncestor:

    def __init__(self, n: int, parent: List[int]):
        # 首先不一定是一个二叉树
        self.log = 16
        self.ancestors = [[-1] * self.log for _ in range(n)]
        # 记录主线
        for i in range(n):
            self.ancestors[i][0] = parent[i]  # 直接父
        for j in range(1, self.log):  # 遍历 上几个祖先
            for i in range(n):  # 遍历所有的节点
                if self.ancestors[i][j - 1] != -1:  # 如果有父
                    # i 节点 的第 j - 1个祖先
                    self.ancestors[i][j] = self.ancestors[self.ancestors[i]
                                                          [j - 1]][j - 1]

    def getKthAncestor(self, node: int, k: int) -> int:
        for j in range(self.log):
            if (k >> j) & 1:
                node = self.ancestors[node][j]
                if node == -1:
                    return -1
        return node
