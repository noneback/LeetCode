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
	分治法思路，归并排序，利用快慢指针找到List的中间节点，递归归并排序
*/
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        return mergeSort(head,nullptr);
    }

    ListNode* mergeSort(ListNode* head,ListNode *tail) {
        if (!head) return head;

        if (head -> next == tail) {
            // in order to prevent fault in merge because of no NULL ending
            // add a null node in the end of the list
            head -> next = nullptr;
            return head;
        }

        // find the mid node using slow and faster pointer
        ListNode *fast = head,*slow = head;

        while (fast != tail) {
            slow = slow -> next;
            fast = fast -> next;
            if (fast != tail) {
                fast = fast -> next;
            }
        }
        // slow one is the mid node

        return merge(mergeSort(head, slow),mergeSort(slow, tail));



    }

    ListNode* merge(ListNode* h1,ListNode* h2) {
        ListNode *fakehead = new ListNode(0), *head = fakehead;
        while (h1 && h2) {
            if (h1 -> val > h2 -> val ) {
                head -> next = h2;
                h2 = h2 -> next;
            } else {
                head -> next = h1;
                h1 = h1 -> next;
            }
            head = head -> next;
        }
        head -> next = h1 ? h1 : h2;

        return fakehead -> next;
    }


};
