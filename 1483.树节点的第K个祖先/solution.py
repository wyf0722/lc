from typing import List

class TreeAncestor:

    def __init__(self, n: int, parent: List[int]):
        self.pa = [[p] + [-1] * 15 for p in parent]
        for j in range(len(self.pa[0])):
            for i in range(n):
                if self.pa[i][j - 1] != -1:
                    self.pa[i][j] = self.pa[self.pa[i][j - 1]][j - 1]

    def getKthAncestor(self, node: int, k: int) -> int:
        for j in range(k.bit_length()):
            if (k >> j) & 1:
                node = self.pa[node][j]
                if node == -1:
                    return node
        return node
    