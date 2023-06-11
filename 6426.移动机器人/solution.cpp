# include "..\leetcode.h"

class Solution {
public:
    int sumDistance(vector<int>& nums, string s, int d) {
        # define LL long long
        int n = s.size();
        LL ans = 0, presum = 0, nn[n];
        for(int i = 0; i < n; i++) {
            if(s[i] == 'L') nn[i] = (LL)nums[i] - d;
            else nn[i] = (LL)nums[i] + d;
        }
        int MOD = 1e9 + 7;
        sort(nn, nn + n);
        /**
         * nums[i] - nums[0] + nums[i] - nums[1] + ... + nums[i] - nums[i - 1]
         * = i * nums[i] - (nums[0] + nums[1] + ... + nums[i - 1])
        */
       for(int i = 0; i < n; i++) {
            ans = (ans + i * nn[i] - presum) % MOD;
            presum += nn[i];
       }
       return ans;
    }
};