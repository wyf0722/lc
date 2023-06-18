# include "..\leetcode.h"

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    int cur = dfs(grid, i, j);
                    ans = max(ans, cur);
                }
            }
        }
        return ans;
    }

    int dfs(vector<vector<int>>& grid, int i, int j) {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
            return 0;
        if(grid[i][j] == 0)
            return 0;
        grid[i][j] = 0;
        return 1 + dfs(grid, i - 1, j)
        + dfs(grid, i, j - 1)
        + dfs(grid, i + 1, j)
        + dfs(grid, i, j + 1);
    }
};


// class Solution {
// public:
//     vector<vector<int>> dir = {{-1, 0},
//                                {1,  0},
//                                {0,  -1},
//                                {0,  1}};

//     int maxAreaOfIsland(vector<vector<int>> &grid) {
//         int ans = 0;
//         for (int i = 0; i < grid.size(); ++i) {
//             for (int j = 0; j < grid[0].size(); ++j) {
//                 if (grid[i][j] == 1) {
//                     // bfs
//                     queue<pair<int, int>> q;
//                     q.push(make_pair(i, j));
//                     grid[i][j] = 0;
//                     int cur = 1;
//                     while (!q.empty()) {
//                         auto [ii, jj] = q.front();
//                         q.pop();
//                         for (int d = 0; d < 4; d++) {
//                             int r = ii + dir[d][0];
//                             int c = jj + dir[d][1];
//                             if(r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size() && grid[r][c] == 1) {
//                                 q.push(make_pair(r, c));
//                                 grid[r][c] = 0;
//                                 cur++;
//                             }
//                         }
//                     }
//                     ans = max(ans, cur);
//                 }
//             }
//         }
//         return ans;
//     }
// };