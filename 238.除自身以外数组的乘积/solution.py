class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        right = [1] * n
        for i in range(n - 2, -1, -1):
            right[i] = right[i + 1] * nums[i + 1]
        left = 1
        for i in range(0, n):
            right[i] = left * right[i]
            left *= nums[i]
        return right