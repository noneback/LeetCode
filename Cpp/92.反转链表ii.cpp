/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head) return nullptr;
        int m = left, n = right;
        int cnt = 1;

        ListNode* pre, *next, *dummyHead = new ListNode(0);
        dummyHead -> next = head;
        pre = dummyHead;

        for (int i = 1;i < left;i++) {
            pre = pre -> next;
        }
        head = pre -> next;

        for (int i = left;i < right;i++) {
            // 将next 和head 换位，更新pre
            auto next = head -> next;
            head -> next = next -> next;
            next -> next = pre -> next;
            pre -> next = next;
        }
        return  dummyHead -> next;     
    }
};
