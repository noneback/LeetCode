import java.lang.reflect.Array;
import java.util.Arrays;

/*
 * @lc app=leetcode.cn id=198 lang=java
 *
 * [198] 打家劫舍
 */

// @lc code=start
class Solution {
    public int rob(int[] nums) {
        if (nums.length == 0 || nums == null)
            return 0;
        if (nums.length == 1)
            return nums[0];
        if (nums.length == 2)
            return Math.max(nums[0], nums[1]);
        int[] sum = new int[nums.length + 1];
        if (nums.length == 3)
        return Math.max(Math.max(sum[0], sum[1]), sum[2]);
        sum[0] = nums[0];
        sum[1] = nums[1];
        sum[2] = nums[2] + nums[0];
       
        int len = nums.length;
        for (int i = 3; i < len; i++) {
                sum[i] = Math.max(sum[i - 3], sum[i - 2]) + nums[i];
            }

        return sum[len-2] > sum[len - 1] ? sum[len-2] : sum[len - 1];

    }
}
// @lc code=end
