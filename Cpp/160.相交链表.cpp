/*
两个链表同时同速遍历，但第一次遍历到结尾之后，移动到另一个链表的头部，使得每个链表的遍历长度相同
如果相交，则有NodeA = NodeB,如果没有，则NodeA == NodeB == Null;

*/



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;
        ListNode *A = headA , *B = headB;

        while (A || B) {
            if (A== B) {
                break;
            }
            if (!A) A = headB;
            else A = A->next;
            if (!B) B = headA;
            else B = B->next;
        }
        return A;
    }
};
