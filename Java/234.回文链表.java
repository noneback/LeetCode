import java.util.ArrayList;
import java.util.List;

/*
 * @lc app=leetcode.cn id=234 lang=java
 *
 * [234] 回文链表
 */

// @lc code=start
/**
 * Definition for singly-linked list. public class ListNode { int val; ListNode
 * next; ListNode(int x) { val = x; } }
 */
class Solution {
    private ListNode fir=null;

    public boolean isPalindrome(ListNode head) {
        fir=head;
        return helper(head);
      
    }

    public boolean helper(ListNode cur){
     if(cur!=null){
         if(!helper(cur.next)) return false;
         if(fir.val!=cur.val) return false;
         fir=fir.next;
     }
     return true;

    }
}
// @lc code=end
