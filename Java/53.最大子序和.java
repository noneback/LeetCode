/*
 * @lc app=leetcode.cn id=53 lang=java
 *
 * [53] 最大子序和
 */

// @lc code=start
class Solution {
    public int maxSubArray(int[] nums) {
        if (nums == null)
            return 0;
        if (nums.length == 1)
            return nums[0];  
        int sum = nums[0], mid = nums[0], i = 1;
        while (i < nums.length) {
            mid = Math.max(nums[i], nums[i] + mid);
            sum = Math.max(mid, sum);
            i++; 
        }
        return sum;
    }
}
// @lc code=end
