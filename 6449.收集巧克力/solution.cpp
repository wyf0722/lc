# include "..\leetcode.h"

class Solution {
public:
    /**
     * 1.最多移动 n - 1次
     * 2.枚举移动次数，统计移动中每个巧克力最小的花费
    */
    long long minCost(vector<int>& nums, int x) {
        int n = nums.size();
        long long ans = LONG_LONG_MAX;
        vector<int> rec(nums);
        // 移动次数 不移动到移动 n- 1 次
        for(int i = 0; i < n; i++) {
            long long sum = 0;
            for(int j = 0; j < n; j++) {
                rec[j] = min(rec[j], nums[(j - i + n) % n]);
                sum += rec[j];
            }
            ans = min(ans, sum + (long long)i * x);
        }
        return ans;       
    }
};

