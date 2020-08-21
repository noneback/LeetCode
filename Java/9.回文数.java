/*
 * @lc app=leetcode.cn id=9 lang=java
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
    public boolean isPalindrome(int x) {
        String mid = "" + x;
        if (x < 0)
            return false;
        else {
            for (int i = 0; i < mid.length() / 2; i++) {
                char a = mid.charAt(i), b = mid.charAt(mid.length() - 1 - i);
                if (a != b)
                    return false;
            }
            return true;
        }

    }
}
// @lc code=end
