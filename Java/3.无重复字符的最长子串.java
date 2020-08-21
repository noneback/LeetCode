import java.util.Hashset;
import java.util.HashSet;

/*
 * @lc app=leetcode.cn id=3 lang=java
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
    public int lengthOfLongestSubstring(String s) {
        if (s == null)
            return 0;
        int len = 0;
        int i = 0, j = 0;// 双指针
        HashSet<Character> set = new HashSet<>();
        while (i < s.length()) {
            if (!set.contains(s.charAt(i))) {
                set.add(s.charAt(i++));
                len = Math.max(set.size(), len);
            } else {
                set.remove(s.charAt(j++));
            }

        }

        return len;
    }
}
// @lc code=end
