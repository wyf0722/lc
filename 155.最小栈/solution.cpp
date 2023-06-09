# include "..\leetcode.h"

class MinStack {
public:
    stack<int> val_s;
    stack<int> min_s;
    
    MinStack() {
        min_s.push(INT_MAX);
    }
    
    void push(int val) {
        val_s.push(val);
        min_s.push(min(val, min_s.top()));
    }
    
    void pop() {
        val_s.pop();
        min_s.pop();
    }
    
    int top() {
        return val_s.top();
    }
    
    int getMin() {
        return min_s.top();
    }
};