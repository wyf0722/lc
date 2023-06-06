class Solution:
    def equalPairs(self, grid: List[List[int]]) -> int:
        n = len(grid)
        ans = 0
        for i in range(n):
            for j in range(n):
                flag = True
                for k in range(n):
                    if grid[i][k] != grid[k][j]:
                        flag = False
                        break
                if flag == True:
                    ans += 1
        return ans