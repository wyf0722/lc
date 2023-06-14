# include "..\leetcode.h"

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // nums1 key=值 value=下标
        unordered_map<int, int> m;
        for(int i = 0; i < nums1.size(); i++) {
            m[nums1[i]] = i;
        }
        vector<int> ans(nums1.size(), -1);
        vector<int> stk;
        for(int i = 0; i < nums2.size(); i++) {
            while(stk.size() && nums2[i] > stk.back()) {
                // 如果栈顶元素在map中， 需要记录答案
                if(m.find(stk.back()) != m.end()) {
                    ans[m[stk.back()]] = nums2[i];
                }
                stk.pop_back();
            }
            stk.push_back(nums2[i]);
        }
        return ans;
    }
};