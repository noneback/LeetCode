import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;

/*
 * @lc app=leetcode.cn id=350 lang=java
 *
 * [350] 两个数组的交集 II
 */

// @lc code=start
class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        if (nums1.length < nums2.length)
            return intersect(nums2, nums1);
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int i : nums1) {
            map.put(i, map.getOrDefault(i, 0) + 1);
        }
        int k = 0;
        for (int i : nums2) {
            int t = map.getOrDefault(i, 0);
            if (t > 0) {
                nums1[k++] = i;
                map.put(i, t - 1);
            }
        }
        return Arrays.copyOf(nums1, k);

    }

}
// @lc code=end
