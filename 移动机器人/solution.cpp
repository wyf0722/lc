# include "..\leetcode.h"

class Solution {
public:
    int sumDistance(vector<int>& nums, string s, int d) {
        int n = s.size();
        for(int i = 0; i < n; i++) {
            if(s[i] == 'L') nums[i] = nums[i] - d;
            else nums[i] = nums[i] + d;
        }
        int ans = 0;
        int mod = 1e9 + 7;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                ans = ((ans % mod) + (abs(nums[j] % mod - nums[i] % mod) % mod)) % mod; 
            }
        }
        return ans;
    }
};