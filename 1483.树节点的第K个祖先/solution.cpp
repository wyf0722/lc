#include "..\leetcode.h"

class TreeAncestor {
   public:
    /**
     * 预处理出每个节点的第 2^i 个祖先节点(1, 2, 4, 8, 16....)
     * pa[i][j] 节点i的第 2^i 个祖先
     */
    vector<vector<int>> pa;

    TreeAncestor(int n, vector<int>& parent) {
        pa = vector<vector<int>>(n, vector<int>(16, -1));
        // 第i个节点的第1个祖先
        for (int i = 0; i < n; i++)
            pa[i][0] = parent[i];
        /**
         * 第i个节点的
         * 第2个祖先 pa[i][1] = pa[pa[i][0]][0]
         * 第4个祖先 pa[i][2] = pa[pa[i][1]][1]
         * 第2^j个祖先 pa[i][j] = pa[pa[i][j - 1]][j - 1]
         *
         * (i, j) 依赖 j - 1列的所有元素, 一列一列算
         * */

        for (int j = 1; j < 16; j++) {
            for (int i = 0; i < n; i++) {
                if (pa[i][j - 1] == -1)
                    continue;
                pa[i][j] = pa[pa[i][j - 1]][j - 1];
            }
        }
    }

    // k转2进制 13(1101) = 8 + 4 + 1
    int getKthAncestor(int node, int k) {
        for (int j = 0; j < 16 && k > 0; j++) {
            // if (k % 2 == 1) {
            //     node = pa[node][j];
            //     if (node == -1)
            //         return -1;
            // }
            // k /= 2;
            // 用二进制表达
            if((k >> j) & 1) {
                node = pa[node][j];
                if(node == -1)
                    break;
            }
        }
        return node;
    }
};

