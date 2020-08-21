
/* 
 * @Description: 
 * @Author: NoneBack
 * @Date: 2020-01-17 20:26:42
 * @Last Modified by: NoneBack
 * @Last Modified time: 2020-01-17 21:49:17
*/
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
/*
 * @lc app=leetcode.cn id=15 lang=java
 *
 * [15] 三数之和
 */

class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> ret = new ArrayList<>();
        if (nums == null || nums.length < 3)
            return ret;
        Arrays.sort(nums);
        for (int i = 0; i < nums.length; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int left = i + 1, right = nums.length - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    ret.add(Arrays.asList(nums[i], nums[left], nums[right]));
                    while (left < right && nums[left] == nums[left + 1])
                        left++;
                    while (left < right && nums[right] == nums[right - 1])
                        right--;
                    left++;
                    right--;
                } else if (sum < 0)
                    left++;
                else if (sum > 0)
                    right--;
            }
        }
        return ret;
    }
}
// @lc code=end
