/*
 * @lc app=leetcode.cn id=7 lang=java
 *
 * [7] 整数反转
 */

// @lc code=start
class Solution {
    public int reverse(int x) {
        long ret = 0;
        while (x != 0) {
            ret *= 10;
            ret += x % 10;
            x /= 10;
        }
        if (ret < Integer.MIN_VALUE || ret > Integer.MAX_VALUE)
            return 0;
        else
            return (int) ret;
    }
}
// @lc code=end
