# include "..\leetcode.h"

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int zero = 0, two = n - 1;
        for(int i = 0; i <= two; i++) {
            if(nums[i] == 0) {
                swap(nums[i], nums[zero]);
                zero++;
            }
            if(nums[i] == 2) {
                swap(nums[i], nums[two]);
                two--;
                if(nums[i] != 1) {
                    i--;
                }
            }
        }
    }
};

