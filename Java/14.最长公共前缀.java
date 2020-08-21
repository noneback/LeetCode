/*
 * @lc app=leetcode.cn id=14 lang=java
 *
 * [14] 最长公共前缀
 */

// @lc code=start
class Solution {
    public String longestCommonPrefix(String[] strs) {
        String ret = "";
        int flags = 0;
        if (strs.length == 0 || strs == null) {
            return "";
        } else if (strs.length == 1) {
            return strs[0];
        }
        String min=strs[0];
        for (int i = 0; i < strs.length; i++) {
            if (min.length() > strs[i].length()) {
                min = strs[i];
            }
        }

        for (int i = 0; i < min.length(); i++) {
            flags = 0;
            for (String str : strs) {
                if (str.charAt(i) != min.charAt(i)) {
                    flags = 1;
                    break;
                }
            }
            if (flags == 0) {
                ret += min.charAt(i);
            } else
                break;
        }

        return ret;
    }
}
// @lc code=end
