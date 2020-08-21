import javax.swing.tree.TreeNode;

/*
 * @lc app=leetcode.cn id=108 lang=java
 *
 * [108] 将有序数组转换为二叉搜索树
 */

// @lc code=start
/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode
 * left; TreeNode right; TreeNode(int x) { val = x; } }
 */
class Solution {
    public TreeNode sortedArrayToBST(int[] nums) {
        return helper(0, nums.length-1, nums);

    }

    public TreeNode helper(int head, int tail, int[] nums) {
        if (head <= tail) {
            int mid = (head + tail) / 2;
            TreeNode ret = new TreeNode(nums[mid]);
            ret.left = helper(head, mid - 1, nums);
            ret.right = helper(mid + 1, tail, nums);
            return ret;
        }
        return null;
    }

}
// @lc code=end
