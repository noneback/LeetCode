import java.lang.reflect.Array;

/*
 * @lc app=leetcode.cn id=2 lang=java
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list. public class ListNode { int val; ListNode
 * next; ListNode(int x) { val = x; } }
 */
class Solution {

    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {

        ListNode ret = new ListNode(0);
        ListNode result = ret;
        ret.next = result;
        int cx = 0;
        
        int mid = 0;
        while (l1 != null && l2 != null) {
            mid = l1.val + l2.val + cx;
            cx = mid / 10;
            result.next = new ListNode(mid % 10);
            result = result.next;
            l1 = l1.next;
            l2 = l2.next;
        }
        ListNode l3 = l1 == null ? l2 : l1;
        while (l3 != null) {
            if(l3!=null){
            mid = l3.val + cx;
            cx = mid / 10;
            result.next = new ListNode(mid % 10);
            result = result.next;
            l3 = l3.next;
            }
        }
        if(cx!=0){
            result.next = new ListNode(cx);
        }

        return ret.next;

    }
}
// @lc code=end
