#include "..\leetcode.h"

class Solution {
public:
    vector<string> ans;

    void help(int left, int right, int n, string ss) {
        if(left == n && right == n) {
            ans.push_back(ss);
            return;
        }
        if(left > n || right > n || right > left) return;
        help(left + 1, right, n, ss + "(");
        help(left, right + 1, n, ss + ")");
    }

    vector<string> generateParenthesis(int n) {
        help(0, 0, n, "");
        return ans;
    }
};


