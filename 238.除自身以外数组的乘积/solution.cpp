# include "..\leetcode.h"

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        // right[i] nums[i]右边所有数字的乘积
        vector<int> right(n, 1);
        for(int i = n - 2; i >= 0; i--) {
            right[i] = right[i + 1] * nums[i + 1];
        }
        int left = 1;
        for(int i = 0; i < n; i++) {
            right[i] = left * right[i];
            left *= nums[i];
        }
        return right;
    }
};