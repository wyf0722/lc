#include "..\leetcode.h"

class NumMatrix {
   public:
    int rec[200][201];

    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        // 列多一位进行存储
        for (int i = 0; i < m; i++) {
            for (int j = 1; j <= n; j++) {
                rec[i][j] = matrix[i][j - 1] + rec[i][j - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = 0;
        for (int i = row1; i <= row2; i++) {
            ans += rec[i][col2 + 1] - rec[i][col1];
        }
        return ans;
    }
};
