class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        s = set()
        a = headA
        while a:
            s.add(a)
            a = a.next
        b = headB
        while b:
            if b in s:
                return b
            b = b.next
        return None      