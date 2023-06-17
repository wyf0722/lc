# include "..\leetcode.h"

class Solution {
public:
    vector<int> grayCode(int n) {
        // grayCode(n - 1) -> grayCode(n)
        vector<int> ans = {0, 1};
        if(n == 1) 
            return ans;
        for(int i = 2; i <= n; i++) {
            for(int j = ans.size() - 1; j >= 0; j--) {
                ans.push_back(ans[j] | (1 << (i - 1)));
            }
        }
        return ans;
    }
};


