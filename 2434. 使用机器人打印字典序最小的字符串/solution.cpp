#include "..\leetcode.h"

class Solution {
   public:
    string robotWithString(string s) {
        int cnt[26] = {0};
        for (auto c : s) {
            cnt[c - 'a']++;
        }
        int minchar = 0;
        while (minchar < 25 && cnt[minchar] == 0) {
            minchar++;
        }
        stack<char> st;
        string ans;
        // 栈顶字符 <= 未入栈字符，出栈
        for (char c : s) {
            cnt[c - 'a']--;
            while (minchar <= 25 && cnt[minchar] == 0) {
                minchar++;
            }
            st.push(c);
            while (!st.empty() && st.top() - 'a' <= minchar) {
                ans.push_back(st.top());
                st.pop();
            }
        }
        return ans;
    }
};