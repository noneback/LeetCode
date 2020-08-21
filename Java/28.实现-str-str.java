/*
 * @lc app=leetcode.cn id=28 lang=java
 *
 * [28] 实现 strStr()
 */

// @lc code=start
class Solution {
    public int strStr(String haystack, String needle) {
        if (needle.length() == 0)
            return 0;

        int[] next = getNext(needle);
        int i = 0, j = 0, len1 = haystack.length(), len2 = needle.length();

        while (j < len2 && i < len1) {
            if (j == -1 || haystack.charAt(i) == needle.charAt(j)) {
                i++;
                j++;
            } else {
                j = next[j];
            }
        }

        return j >= len2 ? i - len2 : -1;
    }

    public int[] getNext(String str) {
        int[] next = new int[str.length()];
        int i = 0, j = 1;
        int len = str.length();
        next[0] = -1;
        while (j < len && i < len) {
            if (i == -1 || str.charAt(i) == str.charAt(j)) {
                next[j] = i;
                j++;
                i++;
            } else {
                i = next[i];
            }
        }
        return next;

    }
}
// @lc code=end
