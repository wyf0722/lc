# include "..\leetcode.h"

class Solution {
public:
    int ans = INT_MAX;
    vector<vector<bool>> rec;

    void help(int x, int y, int cnt) {
        int n = rec.size(), m = rec[0].size();
        if(cnt >= ans) return;
        if(x >= n) {
            ans = cnt;
            return;
        }
        // 当前行填完去下一行填
        if(y >= m) {
            help(x + 1, 0, cnt);
            return;
        }
        // 当前位置被覆盖，尝试下一个位置
        if(rec[x][y]) {
            help(x, y + 1, cnt);
            return;
        }
        // 尝试不同大小的正方形，从大到小尝试，[x][y]未填 
        // [x, n - 1] or [y, m - 1]
        for(int i = min(n - x, m - y); i >= 1 && isValid(x, y, i); i--) {
            fill(x, y, i, true);
            // 跳过该行k个位置
            help(x, y + i, cnt + 1);
            fill(x, y, i, false);
        }
    }

    bool isValid(int x, int y, int len) {
        // 所有位置之前均未覆盖才能进行该次覆盖
        for (int i = x; i < x + len; i++) {
            for(int j = y; j < y + len; j++) {
                if(rec[i][j] == true) return false;
            }
        }
        return true;
    }

    void fill(int x, int y, int len, bool flag) {
        for(int i = x; i < x + len; i++) {
            for(int j = y; j < y + len; j++) {
                rec[i][j] = flag;
            }
        }
    }

    int tilingRectangle(int n, int m) {
        rec = vector<vector<bool>>(n, vector<bool>(m, false));
        help(0, 0, 0);
        return ans;
    }
};
