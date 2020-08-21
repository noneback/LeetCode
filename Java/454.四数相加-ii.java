import java.util.HashMap;
/*
 * @lc app=leetcode.cn id=454 lang=java
 *
 * [454] 四数相加 II
 */

// @lc code=start
class Solution {
    public int fourSumCount(int[] A, int[] B, int[] C, int[] D) {
        int len = A.length;
        HashMap<Integer, Integer> map = new HashMap<>();
        int t;
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                t = A[i] + B[j];
                if (!map.containsKey(t)) {
                    map.put(t, 1);
                } else {
                    map.replace(t, map.get(t) + 1);
                }
            }
        }

        int ret = 0;
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                t = 0 - (C[i] + D[j]);
                if (map.containsKey(t))
                    ret += map.get(t);
            }
        }
        return ret;

    }
}
// @lc code=end
