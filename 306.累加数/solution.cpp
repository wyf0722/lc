#include "..\leetcode.h"

class Solution {
   public:
    vector<long> rec;

    bool helper(string num, int index) {
        if (index == num.size()) {
            return rec.size() > 2;
        }

        long cur = 0;
        for (int i = index; i < num.size(); i++) {
            if (num[index] == '0' && i > index) {
                return false;
            }
            cur = cur * 10 + num[i] - '0';
            if(rec.size() > 2) {
                if(cur > rec[rec.size() - 1] + rec[rec.size() - 2]) {
                    return false;
                }
                if(cur < rec[rec.size() - 1] + rec[rec.size() - 2]) {
                    continue;
                }
            }
            rec.push_back(cur);
            if(helper(num, index + 1)) {
                return true;
            }
            rec.pop_back();
        }
        return false;
    }

    bool isAdditiveNumber(string num) { 
        return helper(num, 0); 
    }
};