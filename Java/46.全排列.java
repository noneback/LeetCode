import java.util.LinkedList;
import java.util.List;

/*
 * @lc app=leetcode.cn id=46 lang=java
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
    public List<List<Integer>> permute(int[] nums) {
        // 回溯算法：tracer,selector,backward,forward
        LinkedList<List<Integer>> ret = new LinkedList<>();
        LinkedList<Integer> tracer = new LinkedList<>();
        trace(ret, tracer, nums);
        return ret;

    }

    public static void trace(List ret, List tracer, int[] nums) {
        // 退出条件
        if (tracer.size() == nums.length) {
            ret.add(List.copyOf(tracer));
            return;
        }
        // selector
        for (var num : nums) {
            if (tracer.contains(num))
                continue;
            tracer.add(num);

            // forward
            trace(ret, tracer, nums);
            // backward
            tracer.remove(tracer.size() - 1);
        }

    }
}
// @lc code=end
