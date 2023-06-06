class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res = []

        def help(l, r, n, cur):
            if l == n and r == n:
                res.append(cur)
                return
            if l < r or l > n or r > n:
                return
            help(l + 1, r, n, cur + '(')
            help(l, r + 1, n, cur + ')')
        help(0, 0, n, '')
        return res