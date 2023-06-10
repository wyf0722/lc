# include "..\leetcode.h"


// !bfs
// class Solution {
// public:
//     int m, n;

//     void bfs(vector<vector<char>>& grid, int i, int j) {
//         queue<pair<int, int>> q;
//         q.push({i, j});
//         grid[i][j] = '0';
//         while(!q.empty()) {
//             auto [x, y] = q.front();
//             q.pop();
//             // 上下左右
//             if(x - 1 >= 0 && grid[x - 1][y] == '1') {
//                 q.push({x - 1, y}); 
//                 grid[x - 1][y] = '0';
//             }
//             if(x + 1 < m && grid[x + 1][y] == '1') {
//                 q.push({x + 1, y}); 
//                 grid[x + 1][y] = '0';
//             }
//             if(y - 1 >= 0 && grid[x][y - 1] == '1') {
//                 q.push({x, y - 1});
//                 grid[x][y - 1] = '0';
//             }  
//             if(y + 1 < n && grid[x][y + 1] == '1') {
//                 q.push({x, y + 1}); 
//                 grid[x][y + 1] = '0';
//             }
//         }
//     }

//     int numIslands(vector<vector<char>>& grid) {
//         m = grid.size();
//         n = grid[0].size();
//         int ans = 0;
//         for(int i = 0; i < m; i++) {
//             for(int j = 0; j < n; j++) {
//                 if(grid[i][j] == '1') {
//                     bfs(grid, i, j);
//                     ans++;
//                 }
//             }
//         }
//         return ans;
//     }
// };

// !dfs
class Solution {
public:
    int m, n;
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    void dfs(vector<vector<char>>& grid, int i, int j) {
        for(int k = 0; k < 4; k++) {
            int xx = dir[k][0];
            int yy = dir[k][1];
            if(i + xx >= 0 && i + xx < m && j + yy >= 0 && j + yy < n && grid[i + xx][j + yy] == '1') {
                grid[i + xx][j + yy] = '0';
                dfs(grid,  i + xx, j + yy);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '1') {
                    grid[i][j] = '0';
                    dfs(grid, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};



