from typing import List

class Solution:
    def closedIsland(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        ans = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 0:
                    q = [[i, j]]
                    grid[i][j] = 1
                    flag = True # 标志位，指示是否封闭
                    while q:
                        ii, jj = q[0][0], q[0][1]
                        q.pop(0)
                        if ii == 0 or ii == m - 1 or jj == 0 or jj == n - 1:
                            flag = False
                        for di, dj in [[-1,0],[1,0],[0,1],[0,-1]]:
                            if(0 <= ii + di < m and 0 <= jj + dj < n and grid[ii + di][jj + dj] == 0):
                                grid[ii + di][jj + dj] = 1
                                q.append([ii + di, jj + dj])
                    if flag:
                        ans += 1
        return ans