/*
 * @lc app=leetcode.cn id=206 lang=javascript
 *
 * [206] 反转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var reverseList = function (head) {
  if (!head || !head.next) return head;
  let pre = null,
    cur = head;
  while (cur) {
    let t = cur.next;
    cur.next = pre;
    pre = cur;
    cur = t;
  }
  return pre;
};

// @lc code=end
