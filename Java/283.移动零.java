/*
 * @lc app=leetcode.cn id=283 lang=java
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
    public void moveZeroes(int[] nums) {
        if (nums == null || nums.length == 0)
            return;
        int i = 0;
        for (int x : nums) {
            if (x != 0)
                nums[i++] = x;
        }

        while (i < nums.length) {
            nums[i++] = 0;
        }

    }
}
// @lc code=end
