# include "..\leetcode.h"

class Solution {
public:
// 左下和右上顶点
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int x_overlap = min(ax2, bx2) - max(ax1, bx1);
        int y_overlap = min(ay2, by2) - max(ay1, by1);
        int overlap = max(0, x_overlap) * max(0, y_overlap);        
        return (ax2 - ax1) * (ay2 - ay1) + (bx2 - bx1) * (by2 - by1) - overlap;
    }
};