#include "..\leetcode.h"

class Solution {
   public:
    int flipChess(vector<string>& chessboard) {
        int m = chessboard.size();
        int n = chessboard[0].size();
        auto bfs = [&](int ii, int jj) {
            vector<string> cb = chessboard;
            queue<pair<int, int>> q;
            q.push({ii, jj});
            cb[ii][jj] = 'X';
            int cnt = 0;  // 记录翻转次数
            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();
                // 8个方向
                for (int i = -1; i <= 1; i++) {
                    for (int j = -1; j <= 1; j++) {
                        if (i == 0 && j == 0)
                            continue;
                        int xx = x + i;
                        int yy = y + j;
                        while (0 <= xx && xx < m && 0 <= yy && yy < n && cb[xx][yy] == 'O') {
                            xx += i;
                            yy += j;
                        }
                        // 如果末尾是黑棋
                        if (0 <= xx && xx < m && 0 <= yy && yy < n && cb[xx][yy] == 'X') {
                            xx -= i;
                            yy -= j;
                            while (cb[xx][yy] != 'X') {
                                cnt++;
                                cb[xx][yy] = 'X';
                                q.push({xx, yy});
                                xx -= i;
                                yy -= j;
                            }
                        }
                    }
                    
                }
            }
            return cnt;
        };
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (chessboard[i][j] == '.') {
                    ans = max(ans, bfs(i, j));
                }
            }
        }
        return ans;
    }
};



















