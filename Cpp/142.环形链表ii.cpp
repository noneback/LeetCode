/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/**
	哈希表记录路径或者使用快慢指针，分析一下快慢指相遇时针与头结点的位置关系
*/
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;

        while(fast) {
            slow = slow -> next;
            if (!fast -> next) return nullptr;
            fast = fast -> next -> next;
            if (slow == fast) {
                ListNode *ptr = head;

                while (ptr != slow) {
                    slow = slow ->  next;
                    ptr = ptr -> next;
                }
                return slow;
            }
        }
        return nullptr;


       
        
    }

};
