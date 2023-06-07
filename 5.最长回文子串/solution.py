class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        ans = [0, 0]
        dp = [[False for _ in range(n)] for _ in range(n)]
        for i in range(n - 1, -1, -1):
            for j in range(i, n):
                if s[i] == s[j] and i + 1 >= j:
                    dp[i][j] = True
                    if j - i > ans[1] - ans[0]:
                        ans = [i, j]
                    continue
                if s[i] == s[j] and dp[i + 1][j - 1] == True:
                    dp[i][j] = True
                    if j - i > ans[1] - ans[0]:
                        ans = [i, j]
                    continue
        return s[ans[0]:ans[1] + 1]