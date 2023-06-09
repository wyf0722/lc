class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        m = len(nums)
        p, q, ans = nums[0], nums[0], nums[0]
        for i in range(1, m):
            p, q = max(p * nums[i], q * nums[i], nums[i]), min(p * nums[i], q * nums[i], nums[i])
            ans = max(ans, p)
        return ans