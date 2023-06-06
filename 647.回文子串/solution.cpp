#include "..\leetcode.h"

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        // dp[i][j] s[i,j]是不是回文子串
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(int i = n - 1; i >= 0; i--) {
            for(int j = i; j < n; j++) {
                // 一个数或者aa
                if(s[i] == s[j] && j - i <= 1) {
                    dp[i][j] = true;
                    ans++;
                    continue;
                }
                // i,j 依赖 i + 1,j - 1
                if(s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    ans++;
                }
            }
        }
        return ans;
    }
};