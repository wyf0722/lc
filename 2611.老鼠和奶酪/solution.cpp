# include "..\leetcode.h"

class Solution {
public:
    // int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
    //     int n = reward1.size();
    //     vector<int> v(n, 0);
    //     iota(v.begin(), v.end(), 0);       
    //     sort(v.begin(), v.end(), [&](int i, int j) { 
    //             return reward1[i] - reward2[i] > reward1[j] - reward2[j];
    //         });
    //     int i = 0, ans = 0;
    //     for(; i < k; i++) {
    //         ans += reward1[v[i]];
    //     }
    //     for(; i < n; i++) {
    //         ans += reward2[v[i]];
    //     }
    //     return ans;
    // }

    // int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
    //     int n = reward1.size();
    //     int ans = 0;
    //     vector<int> rec;
    //     for(int i = 0; i < n; i++) {
    //         ans += reward2[i];
    //         rec.push_back(reward1[i] - reward2[i]);
    //     }
    //     sort(rec.begin(), rec.end(), greater<int>());
    //     for(int i = 0; i < k; i++) {
    //         ans += rec[i];
    //     }
    //     return ans;
    // }

    // 使用小根堆，超过k后，每次pop出最小元素，最后留下最大的k个数
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int n = reward1.size();
        int ans = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i < n; i++) {
            ans += reward2[i];
            pq.push(reward1[i] - reward2[i]);
            if(pq.size() > k) pq.pop();
        }
        while(!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};


