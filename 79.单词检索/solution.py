from functools import cache

class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        m, n = len(board), len(board[0])
        visited = [[False] * n for _ in range(m)]
        directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]

        
        def dfs(x: int, y: int, index: int) ->bool:
            if board[x][y] != word[index]:
                return False
            if board[x][y] == word[index] and index == len(word) - 1:
                return True
            visited[x][y] = True
            for i, j in directions:
                xx, yy = x + i, y + j
                if xx >= 0 and xx < m and yy >= 0 and yy < n and visited[xx][yy] == False:
                    visited[xx][yy] = True
                    if dfs(xx, yy, index + 1):
                        return True
                    visited[xx][yy] = False
            visited[x][y] = False
            return False
        
        for i in range(m):
            for j in range(n):
                if dfs(i, j, 0):
                    return True
        return False



