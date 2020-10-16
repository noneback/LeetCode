/*
 * @lc app=leetcode.cn id=47 lang=java
 *
 * [47] 全排列 II
 */

// @lc code=start
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;

class Solution {
    public List<List<Integer>> permuteUnique(int[] nums) {
        // 回溯算法：tracer,selector,backward,forward
        LinkedList<List<Integer>> ret = new LinkedList<>();
        LinkedList<Integer> tracer = new LinkedList<>();
        boolean[] mark = new boolean[nums.length];
        Arrays.fill(mark, false);
        trace(ret, tracer, nums, mark);
        return ret;

    }

    public static void trace(List<List<Integer>> ret, List tracer, int[] nums, boolean[] mark) {
        // 退出条件
        if (tracer.size() == nums.length) {

            boolean same = false;
            for (List<Integer> result : ret) {
                if (result.equals(tracer)) {
                    same = true;
                    break;
                }
            }

            if (!same)
                ret.add(List.copyOf(tracer));
            return;
        }
        // selector
        for (int i = 0; i < nums.length; i++) {
            if (mark[i])
                continue;
            tracer.add(nums[i]);
            mark[i] = true;
            trace(ret, tracer, nums, mark);
            tracer.remove(tracer.size() - 1);
            mark[i] = false;
        }

    }
}
// @lc code=end
