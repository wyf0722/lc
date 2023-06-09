# include "..\leetcode.h"

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        // f[i, j]以matrix[i, j]做右下角的最大正方形边长
        vector<vector<int>> f(m, vector<int>(n, 0));
        int len = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == '1') {
                    if(i == 0 || j == 0) {
                        f[i][j] = 1;
                    }else {
                        f[i][j] = min(min(f[i - 1][j], f[i][j - 1]), f[i - 1][j - 1]) + 1;
                    }
                }
                len = max(len, f[i][j]);
            }
        }
        return len * len;
    }
};