import java.util.HashMap;

/*
 * @lc app=leetcode.cn id=70 lang=java
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
    public int climbStairs(int n) {
        if(n==1) return 1;
        if(n==2) return 2;
        int[] nums=new int[n+1];
        nums[1]=1;
        nums[2]=2;
        for (int i = 3; i < nums.length; i++) {
            nums[i]=nums[i-1]+nums[i-2];
        }
        return nums[n];

    }

}
// @lc code=end
