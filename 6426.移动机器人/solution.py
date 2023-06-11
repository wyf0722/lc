from typing import List

class Solution:
    def sumDistance(self, nums: List[int], s: str, d: int) -> int:
        n = len(nums)
        MOD = 10**9 + 7
        for i, c in enumerate(s):
            nums[i] = nums[i] - d if c == 'L' else nums[i] + d
        nums.sort()
        ans = presum = 0
        for i, x in enumerate(nums):
            ans += i * nums[i] - presum
            presum += x
        return ans % MOD
