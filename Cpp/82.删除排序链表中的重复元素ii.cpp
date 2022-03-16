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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;

        auto dummy = new ListNode(0), walk = dummy;
        dummy->next = nullptr;
        int cnt = 1;

        while (head) {
            while (head && head->next && head->val == head->next->val) {
                cnt++;
                head = head->next;
            }

            if (cnt == 1) {
                walk->next = head;
                walk = walk->next;
            }

            if (!head || !head->next) break;
            
            cnt = 1;
            head = head->next;
        }

        walk->next = nullptr;
        return dummy->next;
    }
};
