# include "..\leetcode.h"

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        unordered_map<int, ListNode*> m;
        ListNode* cur = dummy;
        int sum = 0;
        while(cur) {
            sum += cur->val;
            m[sum] = cur;
            cur = cur->next;
        }
        sum = 0;
        cur = dummy;
        while(cur) {
            sum += cur->val;
            // cur与 m[sum]之间的所有节点和为零
            // [1,2,-3,3,1] cur = (2) sum = 3 节点(3)和也为3 (2)->next = (3)->next
            cur->next = m[sum]->next;
            cur = cur->next;
        }
        return dummy->next;
    }
};