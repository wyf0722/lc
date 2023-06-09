# include "..\leetcode.h"

class Solution {
public:
    int m;
    int n;
    // 记录是否访问过
    int visited[6][6];
    vector<pair<int, int>> dir{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    // from board[x][y] check word[index, word.size() - 1]
    bool dfs(int x, int y, int index, string word, vector<vector<char>>& board) {
        if(board[x][y] != word[index]) return false;
        // 到达word结尾,并且当前到达board的字符等于word末尾字符
        if(board[x][y] == word[index] && index == word.size() - 1) return true;
        // 上下左右四个方向
        for(auto [i, j]: dir) {
            int xx = x + i;
            int yy = y + j;
            if(xx >=0 && xx < m && yy >= 0 && yy < n && visited[xx][yy] == 0) {
                visited[xx][yy] = 1;
                if(dfs(xx, yy, index + 1, word, board)) return true;
                visited[xx][yy] = 0;
            }
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        memset(visited, 0, sizeof(visited));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                visited[i][j] = 1;
                if(dfs(i, j, 0, word, board)) return true;
                visited[i][j] = 0;
            }
        }
        return false;
    }
};