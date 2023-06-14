from typing import List

class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        if num1 == '0' or num2 == '0':
            return '0'
        ans = '0'
        m, n = len(num1), len(num2)

        for i in range(n - 1, -1, -1):
            cur_ans = ['0'] * (n - 1 - i) # 末尾有多少个零
            add = 0 # 表示进位
            for j in range(m - 1, -1, -1):
                cur = int(num1[j]) * int(num2[i]) + add # 当前数位的乘积
                add = cur // 10 # 使用整除
                cur_ans.append(str(cur % 10))
            if add > 0:
                cur_ans.append(str(add))
            cur_ans = ''.join(cur_ans[::-1])
            ans = self.addStr(ans, cur_ans)
        
        return ans
    
    def addStr(self, num1, num2):
        i, j = len(num1) - 1, len(num2) - 1
        add = 0
        ans = []
        while i >= 0 or j >= 0:
            x = int(num1[i]) if i >= 0 else 0
            y = int(num2[j]) if j >= 0 else 0
            cur = x + y + add
            ans.append(str(cur % 10))
            add = cur // 10
            i -= 1
            j -= 1
        if add > 0:
            ans.append(str(add))
        return ''.join(ans[::-1])