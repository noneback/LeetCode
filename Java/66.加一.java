import java.util.Arrays;
/*
 * @lc app=leetcode.cn id=66 lang=java
 *
 * [66] 加一
 */

// @lc code=start
class Solution {
    public int[] plusOne(int[] digits) {
        if (digits == null || digits.length == 0)
            return null;
        if (digits[0] == 0)
            return new int[] { 1 };
        int ac = 0;
        int[] ret = new int[digits.length + 1];
        digits[digits.length - 1]++;
        for (int i = digits.length - 1; i >= 0; i--) {
            ret[i+1] = (digits[i] + ac) % 10;
            ac = (digits[i] + ac) / 10;
        }
        ret[0]=ac;
        return ac==0?Arrays.copyOfRange(ret, 1, ret.length):ret;

    }
}
// @lc code=end
