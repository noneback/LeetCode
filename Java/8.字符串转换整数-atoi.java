import java.lang.reflect.Array;
import java.util.Arrays;

/*
 * @lc app=leetcode.cn id=8 lang=java
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
class Solution {
    public int myAtoi(String str) {
        str = str.strip();
        if (str == null || str.length() == 0)
            return 0;

        long sum = 0;
        boolean flag = false;
        if (!Character.isDigit(str.charAt(0)) && !(str.charAt(0) == '-' || (str.charAt(0) == '+'))) {
            return 0;
        }

        flag = Character.isDigit(str.charAt(0)) ? false : true;

        int i = flag ? 1 : 0;
        int len = str.length();

        for (char ch : Arrays.copyOfRange(str.toCharArray(), i, len)) {
            if (!Character.isDigit(ch))
                break;

            sum = sum * 10 + (ch - '0');
            if (sum > Integer.MAX_VALUE)
                break;
        }

        if (flag)
            flag = str.charAt(0) == '-' ? true : false;

        if (sum > Integer.MAX_VALUE)
            return flag ? Integer.MIN_VALUE : Integer.MAX_VALUE;
        return flag ? (int) -sum : (int) sum;

    }
}
// @lc code=end
