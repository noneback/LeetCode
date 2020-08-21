import java.lang.reflect.Array;
import java.util.Arrays;

/*
 * @lc app=leetcode.cn id=387 lang=java
 *
 * [387] 字符串中的第一个唯一字符
 */

// @lc code=start
class Solution {
    public int firstUniqChar(String s) {
        if(s==null||s.length()==0) return -1;
        int[] mark = new int[26];
        Arrays.fill(mark, -1);
        for (int i = 0; i < s.length(); i++) {
            int index = s.charAt(i)-'a';
            if (mark[index] == -1) {
                mark[index] = i;
            } else if (mark[index] >= 0) {
                mark[index] = -2;
            } else if (mark[index] == -2) {
                continue;
            }
        }

        for (char ch : s.toCharArray()) {
            int i=ch-'a';
            if(mark[i]>=0)
            return mark[i];
        }

        return -1;

    }
}
// @lc code=end
