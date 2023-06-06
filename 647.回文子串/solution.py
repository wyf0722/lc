class Solution:
    def countSubstrings(self, s: str) -> int:
        n = len(s)
        ans = 0
        dp = [[False] * n for _ in range(n)]
        for i in range(n - 1, -1, -1):
            for j in range(i, n):
                if s[i] == s[j] and j - i <= 1:
                    dp[i][j] = True
                    ans += 1
                    continue
                if s[i] == s[j] and dp[i + 1][j - 1] == True:
                    dp[i][j] = True
                    ans += 1
        return ans