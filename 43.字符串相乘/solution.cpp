# include "..\leetcode.h"

class Solution {
public:
    string addStr(string n1, string n2) {
        int i = n1.size() - 1, j = n2.size() - 1;
        int add = 0;
        string ans = "";
        while(i >= 0 || j >= 0) {
            int ii = i >= 0? n1[i] - '0': 0;
            int jj = j >= 0? n2[j] - '0': 0;
            int res = ii + jj + add;
            ans.push_back('0' + (res % 10));
            add = res / 10;
            i--; 
            j--;
        }
        if(add > 0) {
            ans.push_back('0' + add);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";
        int m = num1.size(), n = num2.size();
        string ans = "0";
        // num1和num2每个数位相乘
        for(int i = n - 1; i >= 0; i--) {
            string cur_ans(n - 1 - i, '0');
            int add = 0;
            for(int j = m - 1; j >= 0; j--) {
                int cur = add + (num1[j] - '0') * (num2[i] - '0');
                add = cur / 10;
                cur_ans.push_back('0' + (cur % 10));
            }
            if(add > 0) {
                cur_ans.push_back('0' + add);
            }
            reverse(cur_ans.begin(), cur_ans.end());
            ans = addStr(ans, cur_ans);
        }
        return ans;
    }
};