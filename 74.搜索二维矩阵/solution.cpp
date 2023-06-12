#include "..\leetcode.h"

class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int i = 0, j = n - 1;
        while (i < m && 0 <= j) {
            if (target < matrix[i][j]) {
                // target小于当前值， 左走
                j--;
            } else if (target > matrix[i][j]) {
                // target大于当前值， 下走
                i++;
            }else {
                return true;
            }
        }
        return false;
    }
};