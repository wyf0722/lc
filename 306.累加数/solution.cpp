#include "..\leetcode.h"

class Solution {
   public:
    bool isAdditiveNumber(string num) {
        for (int i = 1; i < num.size(); i++) {
            for (int j = i + 1; j < num.size(); j++) {
                if (valid(num, 0, i, j))
                    return true;
            }
        }
        return false;
    }

    // num1 [a, b) num2[b, c)
    bool valid(string& num, int a, int b, int c) {
        if (num[a] == '0' && b != a + 1)
            return false;
        if (num[b] == '0' && c != b + 1)
            return false;
        string num1 = num.substr(a, b - a);
        string num2 = num.substr(b, c - b);
        string sum = add(num1, num2);
        if (sum.size() > num.size() - c)
            return false;
        for (int i = 0; i < sum.size(); i++) {
            if (sum[i] != num[c + i])
                return false;
        }
        if(sum.size() + c == num.size())
            return true;
        return valid(num, b, c, c + sum.size());
    }

    // 大数加法
    string add(string& a, string& b) {
        string ans = "";
        int i = a.size() - 1;
        int j = b.size() - 1;
        int flag = 0;
        while (i >= 0 || j >= 0 || flag > 0) {
            int aa = i >= 0 ? a[i--] - '0' : 0;
            int bb = j >= 0 ? b[j--] - '0' : 0;
            ans.push_back((aa + bb + flag) % 10 + '0');
            flag = (aa + bb + flag) / 10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};



