class Solution:
    def tilingRectangle(self, n: int, m: int) -> int:
        rec = [[False for _ in range(m)] for _ in range(n)]
        ans = 1e9

        def dfs(x, y, cnt) -> None:
            nonlocal ans
            if cnt >= ans:
                return
            if x >= n:
                ans = cnt
                return
            if y >= m:
                dfs(x + 1, 0, cnt)
                return
            if rec[x][y] == True:
                dfs(x, y + 1, cnt)
                return
            i = min(n - x, m - y)
            while i >= 1 and isValid(x, y, i) == True:
                fill(x, y, i, True)
                dfs(x, y + i, cnt + 1)
                fill(x, y, i, False)
                i -= 1
            
        def isValid(x, y, len) -> bool:
            for i in range(len):
                for j in range(len):
                    if(rec[x + i][y + j]) == True:
                        return False
            return True
        
        def fill(x, y, len, val: bool) -> None:
            for i in range(len):
                for j in range(len):
                    rec[x + i][y + j] = val
        
        dfs(0, 0, 0)
        return ans