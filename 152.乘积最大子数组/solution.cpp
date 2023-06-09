# include "..\leetcode.h"

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // !dp[i][0] 以nums[i]结尾最大子数组， dp[i][1]以nums[i]结尾最小子数组

        int n = nums.size();
        // int ans = nums[0];
        // vector<vector<int>> dp(n, vector<int>(2, 0));
        // dp[0][0] = nums[0];
        // dp[0][1] = nums[0];
        // for(int i = 1; i < n; i++) {
        //     dp[i][0] = max(max(nums[i], dp[i - 1][0] * nums[i]), dp[i - 1][1] * nums[i]);
        //     dp[i][1] = min(min(nums[i], dp[i - 1][0] * nums[i]), dp[i - 1][1] * nums[i]);
        //     ans = max(ans, dp[i][0]);
        // }
        // return ans;
        int ans = nums[0];
        int maxi = nums[0], mini = nums[0];
        for(int i = 1; i < n; i++) {
            // maxi会被更新
            int temp = maxi;
            maxi = max(max(nums[i] * maxi, nums[i] * mini), nums[i]);
            mini = min(min(nums[i] * temp, nums[i] * mini), nums[i]);
            ans = max(maxi, ans);
        }
        return ans;
    }
};