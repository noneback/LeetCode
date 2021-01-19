/**
 * Definition for singly-linked list->
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
    ListNode* partition(ListNode* head, int x) {
        if(!head || !head->next) return head;

        ListNode fh = ListNode{-99999};
        ListNode* fakeHead = &fh;
        fakeHead->next = head;
        ListNode* ret = fakeHead;

        while(fakeHead->next && fakeHead->next->val < x){
            fakeHead = fakeHead->next;
        }

        ListNode* tmp = fakeHead;

        while(tmp->next){
            if (tmp->next->val >= x){
                tmp = tmp->next;
            }else{
                ListNode *t = tmp->next;
                tmp->next = tmp->next->next;
                t->next = fakeHead->next;
                fakeHead->next = t;
                fakeHead = fakeHead->next;
            }
        }
        return ret->next;
    }
};