# include "..\leetcode.h"

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        // 结果用两个位置存储
        pair<int, int> ans{0, 0};
        // dp[i][j] s[i, j]是否为回文子串
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(int i = n - 1; i >= 0; i--) {
            for(int j = i; j < n; j++) {
                // 一个字符or两个字符(aa)
                if(s[i] == s[j] && i + 1 >= j) {
                    dp[i][j] = true;
                    if(j - i > ans.second - ans.first) {
                        ans = {i , j};
                    }
                    continue;
                }
                // s[i](ss)s[j] ss为回文子串并且s[i]==s[j]
                if(s[i] == s[j] && dp[i + 1][j - 1] == true) {
                    dp[i][j] = true;
                    if(j - i > ans.second - ans.first) {
                        ans = {i , j};
                    }
                }
            }
        }
        return s.substr(ans.first, ans.second - ans.first + 1);
    }
};