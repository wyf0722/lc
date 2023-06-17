from typing import List

class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        rec = {}
        ans = [-1] * len(nums1)
        for i, v in enumerate(nums1):
            rec[v] = i
        stk = []
        for i in range(len(nums2)):
            while stk and stk[-1] < nums2[i]:
                if stk[-1] in rec.keys():
                    ans[rec[stk[-1]]] = nums2[i]
                stk.pop()
            stk.append(nums2[i])
        return ans
