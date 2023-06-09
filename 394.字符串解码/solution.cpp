# include "..\leetcode.h"

class Solution {
public:
    string getNum(string& s, int& index) {
        string ss = "";
        while(s[index] >= '0' && s[index] <= '9') {
            ss.push_back(s[index++]);
        }
        return ss;
    }

    string decodeString(string s) {
        vector<string> stk;
        int index = 0;
        while (index < s.size()) {
            char cur = s[index];
            if(isdigit(cur)) {
                // 是数字的话，取对应的数字放入栈中
                stk.push_back(getNum(s, index));
            } else if(isalpha(cur) || cur == '[') {
                stk.push_back(string(1, s[index++]));
            } else {
                index++;
                // 遇到"]",不断出栈直到找到"["
                vector<string> sub;
                while(stk.back() != "[") {
                    sub.push_back(stk.back());
                    stk.pop_back();
                }
                reverse(sub.begin(), sub.end());
                string curstr = "";
                for(auto i: sub) {
                    curstr += i;
                }
                // 此时stk顶部为 "]"，顶部下面为数字
                stk.pop_back(); // 弹出[
                int num = stoi(stk.back());
                stk.pop_back(); // 弹出数字

                // 重复字符串
                string ss  = "";
                while(num--) {
                    ss += curstr;
                }
                stk.push_back(ss);
            }
        }
        string ans = "";
        for(string i: stk) {
            ans += i;
        }
        return ans;
    }
};