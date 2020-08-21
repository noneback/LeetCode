import java.util.HashMap;

import jdk.nashorn.api.tree.WhileLoopTree;

/*
 * @lc app=leetcode.cn id=13 lang=java
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
class Solution {
    public int romanToInt(String s) {
        HashMap<Character, Integer> map = new HashMap<>();
        String str = "IVXLCDM";
        int[] numbers = new int[] { 1, 5, 10, 50, 100, 500, 1000 };
        for (int i = 0; i < numbers.length; i++) {
            map.put(str.charAt(i), numbers[i]);
        } //
        int result = 0;
        int a = 0, b = 0;
        int i = s.length() - 1;
        while (i >= 0) {
            if (i < s.length() - 1)
                result = map.get(s.charAt(i + 1));

            b = map.get(s.charAt(i));
            if (result == b) {
                a += b;
                i--;
                continue;
            }
            if (a < b) {
                a += b;
            } else {
                a -= b;
            }
            --i;
        }

        return a;

    }
}
// @lc code=end
