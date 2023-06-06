#include "leetcode.h"

class Solution {
public:
    int minDistance(string word1, string word2) {
        // ! dp[i]j] word1[0, i - 1]->word2[0, j - 1]所需的最小步数
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for(int j = 0; j <= n; j++) dp[0][j] = j;
        for(int i = 0; i <= m; i++) dp[i][0] = i;
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(word1[i - 1] == word2[j - 1]) {
                    // 不需要进行操作
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    // 1.替换 2.删除 3.插入
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1; 
                }
            }
        }
        return dp[m][n];
    }
};