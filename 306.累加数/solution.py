from typing import List

class Solution:
    def isAdditiveNumber(self, num: str) -> bool:
        
        rec = []

        def help(num, index: int) -> bool:
            if index == len(num):
                return len(rec) > 2
            cur = 0
            for i in range(index, len(num)):
                if i > index and num[index] == '0':
                    return False
                cur = cur * 10 + int(num[i])
                if len(rec) >= 2:
                    if rec[-1] + rec[-2] < cur:
                        return False
                    if rec[-1] + rec[-2] > cur:
                        continue
                rec.append(cur)
                if help(num, i + 1) == True:
                    return True
                rec.pop()
            return False
        return help(num, 0)