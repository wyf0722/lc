from typing import List

class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        # 第一行和第一列有无零？
        rowFlag = colFlag = False
        for j in range(len(matrix[0])):
            if matrix[0][j] == 0:
                rowFlag = True
                break
        for i in range(len(matrix)):
            if matrix[i][0] == 0:
                colFlag = True
                break
        # 用第一行和第一列存储
        for j in range(1, len(matrix[0])):
            for i in range(1, len(matrix)):
                if matrix[i][j] == 0:
                    matrix[0][j] = matrix[i][0] = 0
        # 赋零
        for j in range(1, len(matrix[0])):
            for i in range(1, len(matrix)):
                if matrix[0][j] == 0 or matrix[i][0] == 0:
                    matrix[i][j] = 0
        if rowFlag:
            for j in range(len(matrix[0])):
                matrix[0][j] = 0 
        if colFlag:
            for i in range(len(matrix)):
                matrix[i][0] = 0
