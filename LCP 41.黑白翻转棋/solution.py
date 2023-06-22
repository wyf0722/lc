from typing import List

class Solution:
    def flipChess(self, chessboard: List[str]) -> int:
        m, n = len(chessboard), len(chessboard[0])

        def bfs(i, j):
            temp = [list(row) for row in chessboard]
            q = []
            q.append([i, j])
            temp[i][j] = 'X'
            cnt = 0
            while q:
                [x, y] = q[0]
                q.pop(0)
                for a in [-1, 0, 1]:
                    for b in [-1, 0, 1]:
                        if a == 0 and b == 0:
                            continue
                        xx, yy = x + a, y + b
                        while 0 <= xx < m and 0 <= yy < n and temp[xx][yy] == 'O':
                            xx, yy = xx + a, yy + b
                        if 0 <= xx < m and 0 <= yy < n and temp[xx][yy] == 'X':
                            xx, yy = xx - a, yy - b
                            while(temp[xx][yy] == 'O'):
                                cnt += 1
                                temp[xx][yy] = 'X'
                                q.append([xx, yy])
                                xx, yy = xx - a, yy - b
            return cnt
        ans = 0
        for i in range(m):
            for j in range(n):
                ans = max(ans, bfs(i, j))
        return ans                 