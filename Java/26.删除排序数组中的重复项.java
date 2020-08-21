/*
 * @lc app=leetcode.cn id=26 lang=java
 *
 * [26] 删除排序数组中的重复项
 */

// @lc code=start
class Solution {
    public int removeDuplicates(int[] nums) {
        if(nums==null||nums.length==0)
        return 0;
        int len = 1;
        int index=0;
        int num = nums[0];
        for (int i = 0; i < nums.length; i++) {
            if (num != nums[i]) {
                nums[len++]=nums[i];
                num = nums[i];
            }
        }

        return len;

    }
}
// @lc code=end
