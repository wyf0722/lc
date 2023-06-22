# include "..\leetcode.h"

class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        // 层数
        int l = min(m / 2, n / 2);
        for(int i = 0; i < l; i++) {
            // 记录这一圈的数字
            vector<int> rec;
            // 上
            for(int j = i; j < n - i; j++) {
                rec.push_back(grid[i][j]);
            }
            // 右
            for(int j = i + 1; j < m - i; j++) {
                rec.push_back(grid[j][n - i - 1]);
            }
            // 下
            for(int j = n - i - 2; j >= i; j--) {
                rec.push_back(grid[m - i - 1][j]);
            }
            // 右
            for(int j = m - i - 2; j >= i + 1; j--) {
                rec.push_back(grid[j][i]);
            }
            int size = rec.size();
            int ii = 0;
            // 上
            for(int j = i; j < n - i; j++) {
                grid[i][j] = rec[(ii + k) % size];
                ii++;
            }
            // 右
            for(int j = i + 1; j < m - i; j++) {
                grid[j][n - i - 1] = rec[(ii + k) % size];
                ii++;
            }
            // 下
            for(int j = n - i - 2; j >= i; j--) {
                grid[m - i - 1][j] = rec[(ii + k) % size];
                ii++;
            }
            // 右
            for(int j = m - i - 2; j >= i + 1; j--) {
                grid[j][i] = rec[(ii + k) % size];
                ii++;
            }
        }
    }
};