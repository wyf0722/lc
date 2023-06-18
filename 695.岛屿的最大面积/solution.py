from typing import List

class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        '''dfs'''
        # def dfs(grid, i, j):
        #     if not 0 <= i < len(grid) or not 0 <= j < len(grid[0]) or grid[i][j] == 0:
        #         return 0
        #     grid[i][j] = 0
        #     return 1 + dfs(grid, i, j - 1) + dfs(grid, i, j + 1) + dfs(grid, i - 1, j) + dfs(grid, i + 1, j)
        # ans = 0
        # for i in range(0, len(grid)):
        #     for j in range(0, len(grid[0])):
        #         cur = dfs(grid, i, j)
        #         ans = max(cur, ans)
        # return ans

        '''bfs'''
        ans = 0
        dir = [[0,1],[0,-1],[1,0],[-1,0]]
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1:
                    q = []
                    q.append([i, j])
                    grid[i][j] = 0
                    cur = 1
                    while(q):
                        ii, jj = q[0][0], q[0][1]
                        q.pop(0)
                        for d in range(4):
                            r, c = ii + dir[d][0], jj + dir[d][1]
                            if 0 <= r < len(grid) and 0 <= c < len(grid[0]) and grid[r][c] == 1:
                                q.append([r, c])
                                grid[r][c] = 0
                                cur += 1
                    ans = max(ans, cur)
        return ans