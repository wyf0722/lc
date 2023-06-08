# include "..\leetcode.h"

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return nullptr;
        ListNode *h1 = headA, *h2 = headB;
        /**
         * -------a
         *        ----c
         *     ---b
         * 相交情况走a + c + b相遇
         * 不相交走完两段链表h1,h2相等为空值
        */
        while(h1 != h2) {
            h1 = h1? h1->next: headB;
            h2 = h2? h2->next: headA;
        }
        return h1;
    }
};