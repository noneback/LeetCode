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

 /**
	分治法，类似归并排序
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return  merge(lists,0,lists.size() - 1);

    }

    ListNode* merge2List(ListNode *h1,ListNode *h2) {
        
        ListNode fakeHead , *t , *a = h1 , *b = h2;
        t = &fakeHead;
        while (a && b) {
            if (a -> val < b -> val) {
                t -> next = a;
                a = a -> next;
            } else {
                t -> next = b;
                b = b -> next;
            }
            t = t -> next;
        }
        t -> next = !a ? b : a;
        return fakeHead.next;
    }

    ListNode* merge(vector<ListNode*> &list,int l,int r) {
        
        if (l == r) return list[l];
        if (l > r) return nullptr;

        int mid = (l + r) >> 1;

        return merge2List(merge(list,l,mid),merge(list,mid + 1,r));
    
    }
};
