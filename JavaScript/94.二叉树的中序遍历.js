/*
 * @lc app=leetcode.cn id=94 lang=javascript
 *
 * [94] 二叉树的中序遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[]}
 */
var inorderTraversal = function(root) {
    let ret = new Array();
    helper(root, ret);
    return ret;
};

var helper = (root, ret) => {
        if (root !== null) {
            helper(root.left, ret);
            ret.push(root.val);
            helper(root.right, ret);
        }
    }
    // @lc code=end