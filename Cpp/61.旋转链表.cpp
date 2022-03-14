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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head -> next) return head;

        auto dummy = new ListNode();
        dummy->next = head;

        // make a circle
        while (head->next) {
            head = head->next;
        }
        head->next = dummy->next;
        head = dummy->next;
        

        auto fast = head, slow = head;
        for (int i = 0;i < k;i++) {
            if (fast->next == dummy->next) {
                k = k % (i + 1) + 1; // 压缩
                i = 0;
            }
            fast = fast->next;
        }
        while (fast->next != dummy->next) {
            slow = slow->next;
            fast = fast->next;
        }
        dummy->next = slow->next;
        slow->next = nullptr;
        return dummy->next;
    }
};
